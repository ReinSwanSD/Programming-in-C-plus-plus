/*****************************************************************************
This template was written by Kazumi Slott for CS111
10-17-2018

This main tests getInt(), getDouble() and getYN() in input.h
*****************************************************************************/
#include <iostream>
using namespace std;
#include "input.h"  //include input.h

int main()
{
  int age;

  cout << "Enter an age: ";
  age = getInt(0, 200, "An age must be between 0 and 200. Enter again: ");
  cout << "age = " << age << endl;

  //Test getInt()
  //get a test score. It should be between 0 and 200.

  int score;

  cout << "Enter an test score: ";
  score = getInt(0, 100, "An age must be between 0 and 100. Enter again: ");
  cout << "score = " << score << endl;

  //Test getInt()
  //get a test score. It should be between 0 and 100.


  double gpa;

  cout << "Enter a gpa: ";
  gpa = getDouble(0.00, 4.00, "A GPA must be between 0.00 and 4.00. Enter again: ");
  cout << "gpa = " << gpa << endl;


  //Test getDouble()
  //get a gpa. It should be between 0.00 and 4.00.

  char answer;

  cout << "Are you a college student? Enter Y or N: ";
  answer = getYN('Y','N',"Your response must be uppercase Y or N. Enter again: ");
  cout << "College Student = "<< answer <<endl;

  //Test getYN()
  //Ask if the user is a college student. It should only accept Y, y, N or n.
  //getYN() returns Y or N only.


  return 0;
}
