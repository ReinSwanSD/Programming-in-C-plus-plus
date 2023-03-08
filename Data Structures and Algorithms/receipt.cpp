/**************

Reinier Swanepoel
CS111
Receipt Lab 
2/10/2020

Create a program the will generate a store receipt.

******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // inputs given
  const double TAX = 7.75; //sales tax percentage needed to find sales tax
  double total; //total after sales tax

  string name; // sales persons name
  string date; // todays date of sale
  string item; // name of item
  double price; //price of the item
  double salesTax; // tax for given item

  //inputs for algo


  //given 

  cout << "Enter sales person's first name: " ; //given
  cin  >> name;

  cout << "Enter today's date(mm/dd/yyyy): " ; //given
  cin  >> date;

  cout << "Enter the item name: "; //given
  cin  >> item;
 
  cout << "Enter the price of the item: " ; //given
  cin  >> price;

  cout<< " "<<endl; //the space in between

  cout <<setw(30)<< "------------------------------" << endl;
  cout<<endl; //the space in between

  // algorithem for tax and total

  salesTax=price * (TAX/100);
  total=salesTax + price;

  cout<< "\"Your Friendly Neighbor Store\"" ;
  cout<<endl; //the space in between
  

  cout << setw(30)<< date << endl << setw(30)<< name<<endl;
  cout<<endl; //the space in between

  cout<<fixed<<setprecision(2);
  cout << left << setw(20)<< item<<right<< setw(10)<< price<< endl;
  cout << left << setw(20)<< "Sales tax" <<right<< setw(10)<< salesTax << endl;
  cout<< left << setw(20) << "Total" <<right<< setw(10)<< total<< endl;
  cout<<endl; //the space in between
  cout <<setw(30)<< "------------------------------" << endl;
  cout<< setw(30)<< "Thank you for shopping with us!";
  cout<<endl; //the space in between

  return 0;

}
