#include <iostream>
#include <cstring>
#include "Hash.h"

using namespace std;

Hash::Hash(){
  int maxsize = 100;
  int cursize = 0;
  int prime = getPrime(maxsize);
  table = new LLL[maxsize];
}

Hash::~Hash(){
  //remove all linked lists
  //delete table
}

//returns prime below current table size
Hash::getPrime(int size){
}
