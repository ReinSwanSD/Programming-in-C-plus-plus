/*******

Reinier Swanepoel
2/28/2020
CS 111

mult Table

Write a program that will display the multiplication table shown below.

*******/



#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

  cout << "     1  2  3  4  5  6  7  8  9" << endl; //in the top as a header
  cout << "------------------------------" << endl; //make a line under it

  for(int row = 1; row <= 9; row++) //first for, start at 1 end at 9, add 1 each time
    {
      cout << setw(2) << row << "|"; //for each row down, count it and label it row number

      for(int col = 1; col <= 9 ; col++) // for each col, create 3 spaces and multiply
	cout << setw(3)<< row*col;
      cout<< endl;   //use setw(3)

      // be sure to skip line
    }
 cout << endl;
  return 0;
}
