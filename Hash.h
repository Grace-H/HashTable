//header file for hash table class

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
  int addStudent(char* first, char* last, int id, float gpa);
  int insert(Student* student, LLL* table);
  Student* retrieve(int id);
  int hash(int id);
  int remove(int id);
  int reHash();
 private:
  int prime;            //prime used for hashing function
  int cursize;          //current number of items in table
  int maxsize;          //capacity of table
  LLL* table;
};

#endif
