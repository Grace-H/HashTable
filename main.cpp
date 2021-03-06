/*Student List: add, remove, print, randomly generate students
 *implements using a hash table as the ADT
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

using namespace std;

int dStudent(Hash* table);
int aStudent(Hash* table);
int aRand(Hash* table, char* lastNames[100], char* firstNames[100], int tFirst, int tLast, int curId);

int main(){
  //command strings
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
  is1.close();
  //convert to char*[]
  char** firstNames = new char*[100];
  int totalFirst = 0;
  char* str;
  str = strtok(first, ",");
  while(str != NULL){
    char* name = new char[20];
    strcpy(name, str);
    firstNames[totalFirst] = name;
    str = strtok(NULL, ",");
    totalFirst++;
  }

  delete [] first;
  
  //last
  char* last = new char[100000];
  ifstream is2("last.txt");
  is2.get(last, 100000);
  is2.close();
  //convert to char*[]
  char** lastNames = new char*[100];
  int totalLast = 0;
  str = strtok(last, ",");
  while(str != NULL){
    char* name = new char[20];
    strcpy(name, str);
    str = strtok(NULL, ",");
    lastNames[totalLast] = name;
    totalLast++;
  }

  delete [] last;
  delete [] str;

  //current student id
  int curId = 100000;

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
      dStudent(table);
    }
    //PRINT
    else if(strcmp(printstr, input) == 0){
      table->displayWhole();
    }
    //ADD RANDOM STUDENT
    else if(strcmp(randomstr, input) == 0){
      curId = aRand(table, firstNames, lastNames, totalFirst, totalLast, curId);
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

//delete a student at ID
int dStudent(Hash* table){
  //get ID
  char* input = new char[256];
  cout << "Enter student ID: " << endl;
  cin.get(input, 256);
  cin.get();
  int id = atoi(input);
  
  //delete student
  int error = table->remove(id);
  if(error == 1){
    cout << "Student did not exist." << endl;
  }
  delete [] input;
  return 0;
}

//ask for student info and add student
//notifies user if ID already in use
int aStudent(Hash* table){
  //first  
  char* first = new char[256];
  cout << "First name: " << endl;
  cin.get(first, 256);
  cin.get();

  //last
  char* last = new char[256];
  cout << "Last name: " << endl;
  cin.get(last, 256);
  cin.get();

  //ID
  char* input = new char[256];
  cout << "Student ID: " << endl;
  cin.get(input, 256);
  cin.get();
  int id = atoi(input);

  //GPA
  cout << "GPA: " << endl;
  cin.get(input, 256);
  cin.get();
  float gpa = atof(input);

  int error = table->addStudent(first, last, id, gpa);
  if(error != 0){
    cout << "Student Id already exists. Student not created." << endl;
    delete [] first;
    delete [] last;
  }

  delete [] input;
  return 0;
}

//asks for number of random students to add, and adds them
//tLast is total last names, same for first
//returns new id value
int aRand(Hash* table, char* firstNames[100], char* lastNames[100], int tFirst, int tLast, int curId){
  char* input = new char[256];
  cout << "How many students?" << endl;
  cin.get(input, 256);
  cin.get();
  int i = atoi(input);
  delete [] input;

  //generate random students
  srand(time(NULL));
  for(int j = 0; j < i; j++){
    //random first and last names
    int firstInt = rand() % tFirst;
    char* first = firstNames[firstInt];
    int lastInt = rand() % tLast;
    char* last = lastNames[lastInt];

    //random gpa
    /*method for generating random float btwn 0.0 and X
     *posted by John Dibling 
     *https://stackoverflow.com/questions/686353/random-float-number-generation
     */
    float gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/4)) + 1;
    int error = table->addStudent(first, last, curId, gpa);
    while(error != 0){
      curId++;
      error = table->addStudent(first, last, curId, gpa);
    }
  }
  return curId++;
}
