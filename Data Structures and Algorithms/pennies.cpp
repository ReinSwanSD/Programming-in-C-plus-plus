/**************

Reinier Swanepoel
CS111
Pennies for Pay
3/3/2020


Write a program that calculates how much a person would earn over a period of time if his or her salary is one penny
the first day and two pennies the second day, and continues to double each day. The program should ask the user for
the number of days she/he worked. Display a table showing how much the salary was for each day, and then show
the total pay at the end of the period. The output should be displayed in a dollar amount, not the number of pennies.
If the user enters an invalid number of days (zero or negative), show an error message and the program should end.
Test your program using the following test cases.

******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ //prompt
  //variables
  int daysWorked; //number of days
  double total=0; //total starts at 0
  double payDays=0.01; //at stated in notes
  int i; //or do int i in the for statement
  //cout ask for days
  cout<< "Enter the number of days you worked: ";
  cin>>daysWorked;//given days worked

  if (daysWorked<=0)    //check if the number is valid
    {
      cout<< daysWorked << " is invalid. Thank you for using the system."<<endl; //for all negative numbers and 0 
    }  
  else//must be postive number
    { 
      cout<<endl<<setw(10)<<right<< "Days" << setw(15) << "Pay"<<endl; //make 25 spaces total
      cout<<"-------------------------"<<endl; //25 '-'
      //algo
      for(i=1; i<=daysWorked;i++) //add one each time 
      {
	if(i==1)
	  payDays= payDays * 1;
	else
	  payDays= payDays *2;

	total+= payDays; //total added up each day

	cout<< fixed <<setprecision(2)<<setw(10) <<right<<1*i << setw(15) <<payDays<<endl; //only show 2 spots .00

      }

      cout<<"-------------------------"; //line at bottom
      //outputs
      cout<< endl << setw(10) <<right << "Total" << setw(15)<< fixed<< setprecision(2)<< total<< endl<< endl;
    }

  return 0;
}
