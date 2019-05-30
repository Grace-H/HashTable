/*Hash table
 *Author: Grace-H
 *Date: 23 May 2019
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "Hash.h"
#include "Student.h" //delete after testing

using namespace std;

int main(){
  Hash* table = new Hash();
  table->getPrime(100);
  table->getPrime(200);
  table->getPrime(400);

  char* first = new char[20];
  char* last = new char[20];
  strcpy(first, "Grace");
  strcpy(last, "Hi");

  table->addStudent(first, last, 123456, 2.34);
  table->addStudent(first, last, 654321, 4.45);

  Student* one = table->retrieve(123456);
  Student* two = table->retrieve(654321);
  cout << one->getId() << endl;
  cout << two->getId() << endl;
  return 0;
}
