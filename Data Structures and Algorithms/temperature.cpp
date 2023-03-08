/*******

Reinier Swanepoel
CS111
Assignment 2
2-8-20
temperature conversion 

This program will ask for a celsius temperature and convert it to
fahrenheit temperature and round it to the nearest integer.

*******/

#include <iostream> // for cin and cout
using namespace std;

int main ()
{
  //variables
  int celsius; //given
  double fahrenheit; //what were looking for 
  int ifahrenheit; //used for rounding

  cout << "Enter a temperature in Celsius: " ; //given
  cin >> celsius ;//input data

  cout << endl; //used to skip line
  //be careful shrinking cin and cout 
  fahrenheit =(double) 9*celsius/5 + 32; //seperate the fractions
  ifahrenheit= (fahrenheit + .5); //rounding
  cout << celsius << "C = " <<ifahrenheit << "F" ; //correct display
  cout<< endl<< endl ; //learn how to space


  return 0;

}

