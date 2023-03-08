/*****************

Reinier Swanepoel
CS111
Assignment 2
2-8-20
lower to upper 

This program will ask for a lowercase letter. It will
then convert it to the corresponding uppercase letter
and display it properly.

*******/

#include <iostream>
using namespace std;


int main ()
{//variables
  char lower;//given var 
  char upper; // conversion to upper
  const int OFFSET = 32; //use words to subtract words,same data type

  cout<< "Enter a lowercase letter: "; //given
  cin>>lower; // take in data 
  //algo
  upper=lower-OFFSET; //all caps const 

  cout<< "The uppercase is " <<upper << "." <<endl <<endl; //use endl so end
  return 0;
}
