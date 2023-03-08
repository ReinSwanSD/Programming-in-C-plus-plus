/***********

Reinier Swanepoel
3/10/2020
Reverse Num

Made a program that will ask for a non-negative integer number (zero or positive value) and show all the
digits backwards.

If the user enters negative numbers, your program should reject them. Once the user enters a non-negative
number, the program should proceed to show all the digits backwards. 
*********/

#include <iostream>//intro needed
#include <iomanip>//necessary
using namespace std;//so we dont have to put it on every line

int main()
{
  int num; //this is the first num entered
    

  cout<< "Enter a non-negative number: ";
  cin>> num;//positive number
  
  while(num<0) //if negative try again
    {
      cout<<"This number is invalid. Enter a number again: ";
      cin>>num;
    }

  do
    { //if positive do math/algo and repeat until number isnt greater than 0
    
     cout << num%10;
     num = num/10; //the last number come first
    }while(num >0);
  cout<<endl;
return 0;
}
