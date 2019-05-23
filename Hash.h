//header file for hash table class

#include <iostream>
#include <cstring>

using namespace std;

class Hash{
 public:
  Hash();
  ~Hash();
  int getPrime(int size);  //gets next smallest prime from table size
  
 private:
  int prime;            //prime used for hashing function
  int cursize;          //current number of items in table
  int maxsize;          //capacity of table
  LLL* table;
};
