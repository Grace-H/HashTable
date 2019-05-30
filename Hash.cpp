#include <iostream>
#include <cstring>
#include "Hash.h"

using namespace std;

Hash::Hash(){
  maxsize = 100;
  cursize = 0;
  prime = getPrime(maxsize);
  table = new LLL[maxsize];
}

Hash::~Hash(){
  //remove all linked lists
  //delete table
}

//returns prime below current table size
Hash::getPrime(int size){
  bool found = true;
  int i = size;
  do{
    found = true;
    i--;
    for(int j = 2; j <= i / 2; j++){
      if(i % j == 0){
	//cout << i << "%" << j << "=" << i % j << endl;
	found = false;
      }
    }
  }while(!found);
  return i;
}

//creates and adds a student to table
//calls insert and rehashes if there are too many collisions
int Hash::addStudent(char* first, char* last, int id, float gpa){
  Student* stu = new Student(first, last, id, gpa);
  int error = insert(stu, table);
  if(error == 1){
    //rehash
  }
  if(cursize >= maxsize / 2){
    //rehash
  }
}

//insert a student into the table
//table is passed in because rehash uses a new table
int Hash::insert(Student* student, LLL* table){
  int index = hash(student->getId());
  //if there is already a LLL at index
  int error = 0;
  error = table[index].insert(student);
  cur++;
  return error;
}

//searches table and returns student pointer given id
Student* Hash::retrieve(int id){
  int index = hash(id);
  return table[index].find(id);
}

int Hash::hash(int id){
  return id % prime;
}

int Hash::reHash(){
  //create a table 2X size
  maxsize = maxsize * 2;
  LLL* newtable = new LLL[maxsize];
  prime = getPrime(maxsize);
  
  //add all items to new table
  int error = 0; //more than three in a slot
  for(int i = 0; i < maxsize / 2; i++){
    //empty slot
    bool empty = false;
    while(!empty){
      Student* stu = table[i].pop();
      if(stu == NULL){
	empty = true;
      }
      else{
	int err = insert(stu, newtable);
	if(err != 0){
	  error = 1;
	}
      }
    }
  }
  LLL* oldTable = table;
  table = newtable;
  delete oldTable;
  
  //if there were three+ collisions
  if(error != 0){
    reHash();
  }
}
