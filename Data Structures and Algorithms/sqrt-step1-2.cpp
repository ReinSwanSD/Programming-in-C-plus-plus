/**************

Reinier Swanepoel
CS111
Square Root
3/3/2020

we will make a function that will calculate the square root of a positive integer number and tell which is closer.
For this assignment, you will write a part of the code. It will go inside a big program later.
Once you figured out how to calculate the top and bottom numbers, then find out between top and bottom
numbers which number is closer to the square root of num
******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ //prompt
  //inputs
  int num,top,bottom,closer;//variables, num is number entered, top is i +1, bottom is i and closer is closer to the num

  cout<< "Enter Num: "; //cout ask for num
  cin>>num;//enter number
  
  for (int i=1; i*i<num;i++) //what squared will get close to num
    {
      bottom=i; //if i times i is i squared
      top=i+1;//the next whole number greater that the bottom which is greater than the number or equal to
    }
  if (((top*top)-num)>(num-(bottom*bottom))) //the num closest to num then add 1 and find that square
    closer=bottom; //if the difference if greater
  else
    closer=top; //if the difference is not greater
  //outputs
  cout<< "Top is " << top<<endl; //top number squared and compared to num entered 
  
  cout<< "Bottom is " << bottom<<endl; //bottom number squared and compared to num entered
  
  cout<< "Between "<<top<<" and " <<bottom<< " , " <<closer<< " is closer."<<endl<<endl; //correct output to show the correct format
  
  return 0;
}
