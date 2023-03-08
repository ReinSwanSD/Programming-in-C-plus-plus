/*******

Reinier Swanepoel
CS111
Assignment 2
2-8-20
Clock

This program will ask for a time in 2 integers: hours and minutes.
It will tell the angles of the hour and minute hands on the clock.

*******/

#include <iostream> // for cin and cout
using namespace std;

int main ()
{// variables
  int hours; //first integer
  int minutes; //second integer
  double hourAngle; //tell the angle of hour hand
  double minuteAngle; //tell the angle of minute hand
  //interface
  cout<< "Enter hours : "; // asking for hours
  cin>> hours ; // user enters

  cout<< "Enter minutes : "; //asking for minutes
  cin>>minutes; // given
  // algo
  hours= hours%12;//12 goes into the hours so many times but then remainder
  hourAngle= 0.5* ( hours * 60 + minutes );//hour hand
  minuteAngle=6*minutes; // minute hand

  cout<< "The angle of the hour hand is : " << hourAngle << endl; //display
  cout<< "The angle of the minute hand is : "<< minuteAngle<< endl<<endl;

  //./a.out to compile


  return 0;

}

