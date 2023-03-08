/**************

Reinier Swanepoel
CS111
Mission Viejo Electric Company
2/21/2020

If the user enters an invalid month, don’t ask the user to enter the meter readings. Your program should
tell the user that the month was invalid and the program should not continue. If the month is valid, ask for
the current and previous readings. The readings cannot be negative numbers. Also the current reading has
to be the same or greater than the previous reading. If not, tell the user the readings are invalid and the
program should not continue. If the month and readings are ok, calculate the amount due.

******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ //prompt
  char ch;
  int month;
  int current;
  int previous;
  string name;
  int consumption;
  double total;
  int iconsumption;

  cout << "Enter your first name: ";
  cin >> name;
  cout << endl;

  cout << "Welcome, "<<name<< "!"<<endl<<"This program will ask for the month and current and previous meter readings then calculate your electric bill. Please press \"<ENTER>\" to continue."<<endl;

  cin.get(ch);
  cin.get(ch);

  cout << "Enter the month: ";
  cin >> month;

  if (month>0 && month<=12)
    {
      cout << "Enter the current meter reading: ";
      cin >> current;
      cout << "Enter the previous meter reading: ";
      cin >> previous;
      cout << endl;

      if (current>previous && current>=0 && previous>=0)
        {
	  consumption=current-previous;
	  cout << fixed << setprecision(2);

	  switch(month)
	    {
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
	      if (consumption>400)
          	{		
	         iconsumption=consumption-400;
	         total=(iconsumption*.07525)+8.50;
		}
	      else
	      	total=8.50;
	      break;
	    case 10:
	    case 11:
	    case 12:
	    case 1:
	    case 2:
	    case 3:
	    case 4:
              if (consumption>400)
                {
		  iconsumption=consumption-400;
		  total=(iconsumption*.06575)+8.50;
                }
              else
                total=8.50;
	      break;

            }
	  cout << "You consumed "<< consumption << " KWH and your amount due is "<< total << endl <<endl;

        }
      else
	cout << "The readings are invalid"<<endl<<endl;

    }
  else 
    cout << month << " is an invalid month"<<endl<<endl;


  return 0;
}
