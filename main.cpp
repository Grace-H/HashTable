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

int aStudent(Hash* table);
int dStudent(Hash* table);
int aRandStudent(Hash* table);

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
      table->display();
    }
    //ADD RANDOM STUDENT
    else if(strcmp(randomstr, input) == 0){
      aRandStudent(table);
    }
    //QUIT
    else if(strcmp(quitstr, input) == 0){
      go = false;
      delete [] addstr;
      delete [] deletestr;
      delete [] randstr;
      delete [] printstr;
      delete [] quitstr;
      delete [] input;
      delete table;
    }
    //not recognized
    else{
      cout << "not an option" << endl;
    }
  return 0;
}
