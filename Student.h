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
  Student(char* first, char* last, int id, float gpa);  //constructor
  ~Student();     //destructor
  char* getFirst();   //returns first name
  char* getLast();    //returns last name
  int getId();        //returns id
  float getGPA();     //returns GPA
  void display();     //displays student info
 private:
  char* first;        //first name
  char* last;         //last name
  int id;             //id
  float gpa;          //gpa
};

#endif
