/*******

Reinier Swanepoel
3/3/2020
CS 111

ASCII Table

Write a program that uses a for loop to display the characters for the ASCII values 35 - 126.Display 14 characters on each line.

*******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int counter =0; //use counter as stated in notes
  
  for (int ascii = 35; ascii <= 126; ascii++) //template for notes, start at char 35 and end char 126
    {
      cout<< (char)ascii <<" "; //display char of the number value
      counter++; //add one each time
      if (counter ==14)//once theres 14 characters on a line
	{
	  counter=0;//reset counter
	  cout<<endl;//skip line
	}
    }//no else needed
  
  cout<<endl;  
  return 0;
}
