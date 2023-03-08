/*******

Reinier Swanepoel
Computer Science CS111
2/14/2020

largest number

program will read 3 numbers and display the largest value of the 3 numbers */

//easy intro
#include <iostream>
using namespace std;

//start this operation
int main ()
{ 
  //variables

  int num1,num2,num3,num4; //all values enetered at the same time
  int largest; //largest

  cout<< "Enter numbers"<<endl; //program will enter 4 intergers
  cin>> num1>>num2>>num3>>num4; //all data entered
  //algo
  if (num1>num2)
    largest=num1; //largest number is num1 drop num2
  else
    largest = num2; //if false drop num1


  if (num3> largest) //if num3 is largest drop num1 and num2
    largest=num3; //if not true then keep previous else


  if (num4> largest) //if num4 is the largest drop num1,2,3
    largest=num4; //if not true then keep previous else
 
  //output

  cout<< "The largest value is " << largest << endl;

  return 0;
}
