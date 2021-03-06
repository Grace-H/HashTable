/*Hash table class
 *Hash function: id % prime below table size
 *Author: Grace Hunter
 *Date: 07 June 2019
 */

#include <iostream>
#include <cstring>
#include "Hash.h"

using namespace std;

//constructor
Hash::Hash(){
  maxsize = 100;
  cursize = 0;
  prime = getPrime(maxsize);
  table = new LLL[maxsize];
}

//destructor
Hash::~Hash(){
  //remove all linked lists
  for(int i = 0; i < maxsize; i++){
    bool empty = false;
    while(!empty){
      table[i].pop();
      empty = table[i].isEmpty();
    }
  }

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
  if(error == 2){
    delete stu;
    return 1;
  }
  if(error == 1){
    reHash();
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

//Hash function
//index = id % prime below table size
int Hash::hash(int id){
  return id % prime;
}

//deletes student by id
//returns 1 if student DNE
int Hash::remove(int id){
  int index = hash(id);
  Student* todelete = table[index].remove(id);
  //if student did not exist
  if(todelete == NULL){
    return 1;
  }
  cursize--;
  delete todelete;
  return 0;
}

//create a new hash table twice the size until collisions are less that 3
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
  table = newtable;
  
  //if there were three+ collisions
  if(error != 0){
    reHash();
  }
  return error;
}

//displays list of students
void Hash::displayWhole(){
  for(int i = 0; i < maxsize; i++){
    table[i].displayStu();
  }
}

//displays all id numbers comma-separated
void Hash::display(){
  for(int i = 0; i < maxsize; i++){
    if(!table[i].isEmpty()){
      table[i].display();
    }
  }
}
