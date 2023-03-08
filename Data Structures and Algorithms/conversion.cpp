/***********
Reinier Swanepoel
CS111
Assignment 2
2-5-2020

Lab on data types, const, type cast, round to a nearest integer
*************************/

#include <iostream> // always use for cin,cout
using namespace std; //standard

int main()
{

  //inputs
  const double CM_INCH=2.54;
  string item; // since the box is a string of letters (multiple letters)
  char fragile; //single character answer
  int centimeters; //using double instead of int because we want decimals
  double inch; //used for the conversion factor
  int iInch;  //int for this
  //part 2 inputs
  int yards; //int is for whole numbers
  int feet; // use mod
  int inches; // mod looks like the percent/ dont get confused with total inches which is inch not inches
  int change; //example

  //cin and cout
  cout << "Enter the name of the item: " ; //example rug
  cin >> item;

  cout << "Is the item fragile? Enter Y or N: " ; //single letter answer either Y or N
  cin >> fragile;

  cout << "Enter the centimeters of the item: " ; //auto conversion using const
  cin >> centimeters ;
 
  cout<< "--------------------------------------------------------------------------"<<endl;

  //calculate algorithem
  inch=centimeters/CM_INCH; //convert  centimeter to inches
  iInch= (int)(inch+0.5);// round up using .5, add 0.5 to a double value and convert the result to int dropping the fraction (type casting) round then use int to drop

  change=iInch;
  //calculate algorithem for the yards,feet,inches
  yards = change /36;// test case 1=123 inch total, 36 goes into 123 3 times with a remainder of 15
  change =(int)change%36; // remainder of 15
  feet = change/12; // to answer is 12 goes into 15 1 time
  change =(int) change%12; //with the remainder of 3
  inches = change; //the remainder inches is just equal to the remainder


  //display outputs
  cout << item << "(" <<fragile<< ")" <<endl; //outputs changed the length to inch and iInch
  cout << centimeters << " cm is about " <<inch<< " inches rounded to "<<iInch<< " inches."<<endl;// end of conversion part 1
   cout << iInch << " inches = " << yards << " yards, " << feet << " feet, and " << inches << " inches. " <<endl; //conversion part 2 output
  cout<< "--------------------------------------------------------------------------"<<endl;
  
  cout<< "Thank you for using the program. Good bye."<<endl;
  cout<< " "<<endl;
  return 0;
}
