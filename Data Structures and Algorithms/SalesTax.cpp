/*****************************************
Reinier Swanepoel
CS111
2.3.2020

This program will ask the user to enter the price
of an item and the sales tax rate. It will show the tottal purchase price.
**************************************/

#include <iostream>  // must be included for cout to work
using namespace std;  // must be included

int main()//how to start
{//inputs first
  //num1=Price
  //num2=Tax Rate

  double num1; //  retail price of the item being purchase
  double num2; // sales tax
  double sum; // sale tax to be added
  double total; //total of sale item
  // get num1 and num2

  cout<< "Enter the price of the item: ";
  cin>> num1;//copy with highlighting and press right click to paste

  cout<< "Enter the sales tax of the item: ";
  cin>> num2;

  //algo calculate the sales tax ammount and total
  //outputs
  sum=(num1*num2);
  total=(sum + num1);
  //input data

  cout<< "The Sales tax for the purchase is " <<sum<< endl;
  cout<< "The price of the total sale item is " <<total<< endl;

  //  cout << "Hi"  << endl  ; // thats an L not a 1



  return 0;  //end
}
// save with controll x+c and y to confirm
