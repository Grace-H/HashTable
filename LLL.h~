/*header file for linear linked list class data: Student*
 *Author: Grace-H
 *Date: 28 May 2019
 */

#include <iostream>
#include <cstring>
#include "Student.h"

#ifndef LLL_H
#define LLL_H

using namespace std;

struct node{                    //LLL node
  Student* student;             
  node* next;
};
  
class LLL{
 public:
  LLL();                        //constructor
  ~LLL();                       //destructor
  int insert(Student* student); //adds student to list
  Student* find(int id);        //locates and returns Student* pointer
  Student* remove(int id);      //removes student
  Student* pop();               //returns & removes head
  void display();
  void displayStu();
  bool isEmpty();
 private:
  node* head;                  //head of list
  int size;                    //length of list
};

#endif
