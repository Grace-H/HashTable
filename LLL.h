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

struct node{
  Student* student;
  node* next;
};
  
class LLL{
 public:
  LLL();
  ~LLL();
  int inset(Student* student);
  Student* remove(int id);
 private:
  node* head;
  int size;
};

#endif
