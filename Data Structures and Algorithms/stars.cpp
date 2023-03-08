/*******

Reinier Swanepoel
3/3/2020
CS 111

Stars

Write a program that will display the number into n then your program will show 1 star on the first line and 2 star the second line......n stars on the nth line as show below. if the user enters a negative number or zero show an error message and the program ends

*******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ //prompt
  int num; //first variable used for num of row

  cout<< "Enter the number of rows: ";
  cin >> num; //user enteres number of rows

  if (num==0 || num<0) //check if it is more than or equal to 1
    {//if number isnt valid
      cout<< "This program works for n >= 1 only"<<endl;
    }
  else//for all real case for numbers greater than 1
    {
      for (int row = 1; row<=num; row++) //first for statement for the rows
	{
	  for (int i= num;i > row;i--) //second for statement for the space before the stars
	    cout<<" ";
	  for (int col = 1; col<=row; col++) //third for statement for the stars to be equal to ammount of rows
	    cout<< "*";
	  cout<<endl; //skip a line to match format
    }
      cout<<endl; //make sure to skip a line 
    }
  return 0;
}
