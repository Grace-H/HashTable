/*Hash table
 *Author: Grace-H
 *Date: 23 May 2019
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "Hash.h"
#include "Student.h" //delete after testing

using namespace std;

int aStudent(Hash* table);
int dStudent(Hash* table);
int aRand(Hash* table, char* lastNames[100], char* firstNames[100], int tFirst, int tLast);

int main(){
  char* addstr = new char[20];
  char* deletestr = new char[20];
  char* printstr = new char[20];
  char* quitstr = new char[20];
  char* randomstr = new char[20];

  strcpy(addstr, "ADD");
  strcpy(deletestr, "DELETE");
  strcpy(printstr, "PRINT");
  strcpy(quitstr, "QUIT");
  strcpy(randomstr, "RANDOM");

  //read in names for random student generator
  //first
  char* first = new char[100000];
  ifstream is1("first.txt");
  is1.get(first, 100000);
  cout << first << endl;
  is1.close();
  char* firstNames[100];
  int totalFirst = 0;
  char* str;
  str = strtok(first, ",");
  while(str != NULL){
    firstNames[totalFirst] = str;
    str = strtok(NULL, ",");
    totalFirst++;
  }
  
  //last
  char* last = new char[100000];
  ifstream is2("last.txt");
  is2.get(last, 100000);
  cout << last << endl;
  is2.close();
  char* lastNames[100];
  int totalLast = 0;
  str = strtok(first, " ");
  while(str != NULL){
    firstNames[totalLast] = str;
    str = strtok(NULL, " ");
    totalLast++;
  }

  char* input = new char[256];
  
  cout << "node: commands do not have to be uppercase" << endl;

  Hash* table = new Hash();

  bool go = true;
  while(go){
    //get input
    cout << "'ADD', 'DELETE', 'PRINT', add 'RANDOM' student, or 'QUIT'?" << endl;
    cin.get(input, 256);
    cin.get();

    //uppercase
    for(int i = 0; i < strlen(input); i++){
      input[i] = toupper(input[i]);
    }

    //identify command a perform action
    //ADD
    if(strcmp(addstr, input) == 0){
      aStudent(table);
    }
    //DELETE
    else if(strcmp(deletestr, input) == 0){
      //dStudent(table);
    }
    //PRINT
    else if(strcmp(printstr, input) == 0){
      table->displayWhole();
    }
    //ADD RANDOM STUDENT
    else if(strcmp(randomstr, input) == 0){
      aRand(table, firstNames, lastNames, totalFirst, totalLast);
    }
    //QUIT
    else if(strcmp(quitstr, input) == 0){
      go = false;
      delete [] addstr;
      delete [] deletestr;
      delete [] randomstr;
      delete [] printstr;
      delete [] quitstr;
      delete [] input;
      delete table;
    }
    //not recognized
    else{
      cout << "not an option" << endl;
    }
  }
  return 0;
}

int aStudent(Hash* table){
  char* first = new char[256];
  cout << "First name: " << endl;
  cin.get(first, 256);
  cin.get();

  char* last = new char[256];
  cout << "Last name: " << endl;
  cin.get(last, 256);
  cin.get();

  char* input = new char[256];
  cout << "Student ID: " << endl;
  cin.get(input, 256);
  cin.get();
  int id = atoi(input);

  cout << "GPA: " << endl;
  cin.get(input, 256);
  cin.get();
  float gpa = atof(input);

  table->addStudent(first, last, id, gpa);
  delete [] input;
}

int aRand(Hash* table, char* lastNames[100], char* firstNames[100], int tFirst, int tLast){
  char* input = new char[256];
  cout << "How many students?" << endl;
  cin.get(input, 256);
  cin.get();
  int i = atoi(input);
  delete [] input;
  
  srand(time(NULL));
  for(int j = 0; j < i; j++){
    //random first and last names
    int firstInt = rand() % tFirst;
    char* first = firstNames[firstInt];
    int lastInt = rand() % tLast;
    char* last = lastNames[lastInt];

    //random id & gpa
    int id = rand() % 899999 + 100000;
    float gpa = rand() / RAND_MAX * 4.00;
    cout << "GPA: " << gpa << endl;
    
    table->addStudent(first, last, id, gpa);
  }
  return 0;
}
