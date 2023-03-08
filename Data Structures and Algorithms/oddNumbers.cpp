/*******

Reinier Swanepoel
CS111
Odd Numbers
2/24/2020

Make a program that will display the double and triple for all odd
numbers from 99 down to 1. Make your outputs lined up as follows (the numbers as well
as the labels are lined up to the right). 

*******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ //code starts stream

  int num;
  int total;
  cout << setw(10) << "Number" << setw(10) << "Double" << setw(10) << "Triple" << endl; //header on the top, doesnt need torepeat
 
  for (int i=99;i>=1;i-=2) //make sure u use the semi colons
    { //brackets not needed
      cout << setw(10) << i << setw(10) << i*2 <<setw(10)<< i*3 <<endl;
    }

  return 0; //useful for code
}
