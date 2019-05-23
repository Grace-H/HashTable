//header file for student class

#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student();
  ~Student();
 private:
  char* first;
  char* last;
  int id;
  float gpa;
};
