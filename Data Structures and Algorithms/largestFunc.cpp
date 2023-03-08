/*******

Reinier Swanepoel
3/4/2020
CS111

Largest Funct

1.Make a program will read 3 positive numbers from the user and tell the largest number. Make the
following 4 functions in addition to the main function.
2.This function asks the user to enter a positive number and returns it. Keep rejecting an invalid number
(negative or zero) using a while loop. (3 times)
3.This function finds the largest value among the 3 numbers and returns it. Use the following format.
4.This function shows the result in the following format. Assume the user entered 3, 5 and 1 in this order.
The largest number among 3, 5 and 1 is 5. 

*******/

#include <iostream>
using namespace std;
//prototypes
void showProgInfo(); 
int getNum();
int findLargest(int n1, int n2, int n3);
void printResult(int largest,int num1,int num2,int num3);

//main function
int main()
{
  //variables
  int num1;//first positive number entered
  int num2;//second positive number entered
  int num3;//third positive number entered
  int largest;//largest number
  
  showProgInfo( );
  num1 = getNum(); //line 1
  num2 = getNum(); //line 2
  num3 = getNum(); //line 3
  largest = findLargest(num1, num2, num3); //dont need int since variables are already declared
  printResult(largest,num1,num2,num3); //print results
  
  return 0;
}

/********************

This function will show the program information shown below.

******************/
void showProgInfo( )
{
  cout << "*****************************************************" <<endl;
  cout << "This program will ask you to enter 3 numbers and find the largest. " <<endl;
  cout << "*****************************************************" <<endl;
}
/********************

This function asks the user to enter a positive number and returns it. Keep rejecting an invalid number
(negative or zero) using a while loop.

******************/

int getNum( )
{
  int num; //users imput
  
  cout << "Enter a positive number: "; //given from user
  cin >> num;
  
  while(num<0 || num==0) //check and make sure its a valid entry
    {
      cout << num << " is invalid. Enter a positive number: ";
      cin >> num;
    }
  
  
  return num; //return num
}
/********************

This function finds the largest value among the 3 numbers and returns it. Use the following format.

******************/


int findLargest(int n1,int n2,int n3)//use different variables
{
  int largest; //declare largest
  
  if (n1>n2)
    {
      largest=n1; //largest number is num1 drop num2
    }
  else
    {
      largest = n2; //if false drop num1
    }
  
  if (n3> largest) //if num3 is largest drop num1 and num2
    {   
      largest=n3; //if not true then keep previous else
    }
  
  //output
  
  return largest; //return largest
}

/********************

This function shows the result in the following format. Assume the user entered 3, 5 and 1 in this order

******************/

void printResult(int largest,int num1,int num2,int num3) //declare variables
{
  cout<< "The largest number among "<< num1 << ", "<<num2<<" and "<<num3<<" is "<< largest << "."<< endl; //outputs
  
}
