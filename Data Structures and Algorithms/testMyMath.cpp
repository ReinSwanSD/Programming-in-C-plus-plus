/*******

Reinier Swanepoel

this program will use the power function

******/

#include <iostream>
using namespace std;
#include "myMath.h"


int main()
{
  int ans,base,exp,product; // variables
  double iNum,num,jNum,dNum; //dnum is value to be rounded, num is given value, inum is absolute value, jnum is rounded value

  //power test

  ans = pow(2,3); //auto math
  cout << ans<< endl; //display answer

  //
  // exponent 
  cout << "Enter a base : "; //ask user
  cin >> base; //store data

  cout << "Enter a exponent : "; //ask again
  cin >> exp;//store again

  product = pow(base, exp); //math function
  cout << product << endl; //display answer
  // absolute value
  cout << "Enter a number and find the absolute value : "; //ask for number
  cin >> num; //store number and get ready to fabs

  iNum = fabs(num); //apply function
  cout << iNum<<endl; //display answer

  cout << "Enter a number and round the value : "; //ask first
  cin>>dNum; //ask for a different number

  jNum = round(dNum); //do the math function

  cout << jNum <<endl; //output the answer
  return 0;
}
