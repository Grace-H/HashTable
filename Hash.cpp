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
int Hash::getPrime(int size){
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
//returns 1 if student id already exists
int Hash::addStudent(char* first, char* last, int id, float gpa){
  Student* stu = new Student(first, last, id, gpa);
  int error = insert(stu, table);
  cout << "Before rehashing checks: " << endl;
  display();
  if(error == 2){
    delete stu;
    return 1;
  }
  if(error == 1){
    reHash();
    display();
  }
  return 0;
}

//insert a student into the table
//table is passed in because rehash uses a new table
int Hash::insert(Student* student, LLL* table){
  int index = hash(student->getId());
  //if there is already a LLL at index
  int error = 0;
  error = table[index].insert(student);
  if(error != 2){
    cursize++;
  }
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
  int error = 0; //!1 = more than three in a slot
  for(int i = 0; i < maxsize / 2; i++){
    //empty slot
    bool empty = false;
    int pops = 0;
    while(!empty){
      pops++;
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
    cout << "pops: " << pops << endl;
  }
  LLL* oldTable = table;
  table = newtable;
  delete oldTable;
  
  //if there were three+ collisions
  if(error != 0){
    cout << "REHASHING BECAUSE THERE WERE COLLISIONS" << endl;
    reHash();
  }

  return error;
}

void Hash::displayWhole(){
  for(int i = 0; i < maxsize; i++){
    table[i].displayStu();
  }
}

void Hash::display(){
  for(int i = 0; i < maxsize; i++){
    if(!table[i].isEmpty()){
      table[i].display();
    }
  }
}
