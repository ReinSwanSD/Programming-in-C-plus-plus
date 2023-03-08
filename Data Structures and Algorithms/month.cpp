/**************

Reinier Swanepoel
CS111
Month
2/21/2020


Your program will ask for a month (1 for January, 12 for December) and tell the season
(spring for March to May, summer for June to August, fall for September to November,
and winter for December to February). If the user enters an invalid month, say “Invalid
month”. 

******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

  int month;

  cout<< "Enter a month(1 for January, 12 for December):"<<endl;
  cin>> month; // the user will enter 0-13

  switch(month) //month 
  {
   case 13: //invalid
   case 0: cout << "Invalid month"<<endl;
      break;
   case 3://spring
   case 4:
   case 5:cout <<"Spring"<<endl;
     break;
   case 6://summer
   case 7:
   case 8:cout <<"Summer"<<endl;
     break;
   case 9://fall
   case 10:
   case 11:cout <<"Fall"<<endl;
     break;
   case 12://winter
   case 1:
   case 2:cout << "Winter"<<endl;
     break;

   default: cout<< "Invalid month"<<endl; //if all else
  }


  int i=0;
  i+3;
  cout<< i;












  return 0; //to end code
}

