/*Linked list class, holds Student*
 *Author: Grace-H
 *Date: 28 May 2019
 */

#include <iostream>
#include <cstring>
#include "LLL.h"

using namespace std;

//constructor
LLL::LLL(){
  head = NULL;
  size = 0;
}

//destructor
LLL::~LLL(){
  while(head != NULL){
    remove(head->student->getId());
  }
}

//add a student to list
//returns 1 if more than 3 in list
//returns 2 if there is already student with that id
int LLL::insert(Student* student){
  //create a new node
  node* n = new node;
  n->student = student;
  n->next = NULL;
  
  //if list is empty
  if(size == 0){
    head = n;
  }
  //insert node at end of list
  else{
    node* cur = head;
    while(cur->next != NULL){
      cout << "cur->student->getId(): " << cur->student->getId() << endl;
      if(cur->student->getId() == student->getId()){
	cout << "STUDENT IDS ARE THE SAME" << endl;
	return 2;
      }
      cur = cur->next;
    }
    if(cur->student->getId() == student->getId()){
      return 2;
    }
    cur->next = n;
  }

  //increase size
  size++;

  //return 1 if size is greater than 3
  if(size > 3){
    return 1;
  }
  return 0;
}

//returns student pointer
//does not remove student
Student* LLL::find(int id){
  //find student
  node* cur = head;
  while(cur != NULL){
    if(cur->student->getId() == id){
      return cur->student;
    }
  }
  //student DNE
  return NULL;
}

//remove a student from list
//returns NULL if student didn't exist
Student* LLL::remove(int id){
  //find student
  node* prev = NULL;
  node* cur = head;
  while(cur != NULL){
    if(cur->student->getId() == id){
      //change pointers
      if(prev = NULL){
	head = cur->next;
      }
      else{
	prev->next = cur->next;
      }
      //return the student
      Student* student = cur->student;
      delete cur;
      return student;
    }
    cur = cur->next;
  }
  //no student was found
  return NULL;
}

Student* LLL::pop(){
  cout << "size of list: " << size << endl;
  cout << "list: ";
  display();
  cout << endl;
  if(head != NULL){
    Student* stu = head->student;
    node* cur = head;
    head = head->next;
    delete cur;
    size--;
    return stu;
  }
  else{
    return NULL;
  }
}

void LLL::display(){
  node* cur = head;
  while(cur){
    cout << cur->student->getId() << ", ";
    cur = cur->next;
  }
}

void LLL::displayStu(){
  node* cur = head;
  while(cur){
    cur->student->display();
    cur = cur->next;
  }
}

//returns true if list is empty
bool LLL::isEmpty(){
  if(head == NULL){
    return true;
  }
  else{
    return false;
  }
}
