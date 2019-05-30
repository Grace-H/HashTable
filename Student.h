/*header file for student class
 *Author: Grace-H
 *Date: 28 May 2019
 */

#include <iostream>
#include <cstring>

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student{
 public:
  Student(char* first, char* last, int id, float gpa);
  ~Student();
  char* getFirst();
  char* getLast();
  int getId();
  float getGPA();
  int display();
 private:
  char* first;
  char* last;
  int id;
  float gpa;
};

#endif
