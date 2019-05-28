/*Student Class
 *Author: Grace-H
 *Date: 28 May 2019
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "Student.h"

using namespace std;

//constructor
Student::Student(char* newfirst, char* newlast, int newid, float newgpa){
  first = newfirst;
  last = newlast;
  id = newid;
  gpa = newgpa;
}

//destructor
Student::~Student(){
  delete [] first;
  delete [] last;
}

//returns first name
char* Student::getFirst(){
  return first;
}

//returns last name
char* Student::getLast(){
  return last;
}

//returns student id number
int Student::getId(){
  return id;
}

//returns GPA
float getGPA(){
  return gpa;
}

//display student's info to console
//returns 1 if either name DNE
int Student::display(){
  if(first != NULL && last != NULL){
    cout << first << " " << last << ", " << id << ", " << gpa << endl;
    return 0;
  }
  else{
    return 1;
  }
}
