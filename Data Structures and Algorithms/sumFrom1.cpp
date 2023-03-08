/**************

Reinier Swanepoel
CS111
Sum From 1
2/24/2020

Write a program that will ask the user for a positive integer value.
The program should use the for loop to get the sum of all the integers from 1 up to
the number entered. For example, if the user enters 50, the loop will find the sum of 1,
2, 3, 4, ... 50. If the user enters a zero or negative number, a message should be given
and the program should not continue 

******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  //code starts stream
  int num; // integer for whole 
  int total; //total of all numbers

  cout << "Enter a positive number: ";
  cin >> num; //given
  cout << endl; //skip line
  if(num>0) //num is greater than 0 or do num<=0
    {
      for (int i=1;i<=num;i++) //for loop
     
	total += i; //total
    
      cout << "The sum of all the numbers from 1 to "<< num << " is " << total << "."<<endl<<endl; //cout proper
    }
  else  // num is not greater than 0 or do all numbers greater than 0
    cout << num << " is invalid."<<endl<<endl;


  return 0; //how to end
}

