/******

Reinier Swanepoel
3/10/2020
Fibonacci numbers

Write a program that will show Fibonacci numbers. The program should ask for the number of Fibonacci
numbers the user wants to see (N >= 3). You need to reject invalid numbers that are less than 3. Once the
user enters a valid N, it will show the first N fibonacci numbers.

*****/

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
  int num; //answer to question
  int num1=0;//first one hardcoded
  int num2=1;//second one hardcoded
  int i; //num -3 is i
  int total;//same as sum
  
  cout<<"Enter the number of fibonnacci numbers that you want to see (N>=3):";
  cin>>num; //we need for answers 2 or 1 numbers or 0
  
  while(num<3)//if we want to see 3 or more numbers
    {
      cout<<"Enter the number of fibonnacci numbers that you want to see (N>=3):";
      cin>>num;//ask again if the user enters a number less than 3
    }
  //algo or make a for loop
  
  //num --3 is i
  cout<<num1<<" "<<num2<<" "; //cout if just one or two numbers
  

  i= (num-3);
  while(i>=0) //for more than 2 numbers
    {
      total=num1+num2; //n1 + n2 and keep it going
      cout<<total<<" "; //display total
      num1=num2;//again
      num2=total;//next run and repeat
      i--; //until 0
    }
  cout<<endl; //skip line
  return 0;
}
