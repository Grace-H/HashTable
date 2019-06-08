//header file for hash table class
//Author: Grace-H
//Date: 07 June 2019

#include <iostream>
#include <cstring>
#include "Student.h"
#include "LLL.h"

#ifndef HASH_H
#define HASH_H

using namespace std;

class Hash{
 public:
  Hash();
  ~Hash();
  int getPrime(int size);  //gets next smallest prime from table size
  int addStudent(char* first, char* last, int id, float gpa);  //create and add student to table
  int insert(Student* student, LLL* table);   //insert student at correct location in table
  Student* retrieve(int id);   //return student given id
  int hash(int id);    //hash function
  int remove(int id);   //remove student given id
  int reHash();    //create new table 2X size and rehash everything into it
  void displayWhole();    //display students
  void display();    //display id numbers
 private:
  int prime;            //prime used for hashing function
  int cursize;          //current number of items in table
  int maxsize;          //capacity of table
  LLL* table;           //table
};

#endif
