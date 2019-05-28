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
//returns 1 if more than 3 in chain
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
      cur = cur->next;
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
      delete node;
      return student;
    }
    cur = cur->next;
  }
  //no student was found
  return NULL;
}
