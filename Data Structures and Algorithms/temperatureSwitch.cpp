/**************

Reinier Swanepoel
CS111
Temperature Switch
2/10/2020

Your program will convert a temperature between Fahrenheit and Celsius. Your program will ask the user to enter an
F or C (F if he has a temperature in Fahrenheit and C if he has a temperature in Celsius). It will then convert the
temperature to the other unit. You MUST use switch for this program.

******/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ //prompt
  
  char temperature; //for users entered temp in either F or C
  double celsius; //data for celsius
  double fahrenheit; //data for fahrenheit
  //ask user for F or C
  cout<< "Which temperature do you have? Enter F for Fahrenheit or C for Celsius?: ";
  cin >> temperature;
  //algo
  switch(temperature) //if user entered f,F,c C, or everything thats not that
    {
    case 'F': //fahrenheit
    case 'f': //fahrenheit
      cout << "Enter a temperature in Fahrenheit: ";
      cin >> fahrenheit; //entered temperature to be converted
      
      celsius=(double)(fahrenheit -32.00) * 5.00/9.00; //conversion from fahrenheit to celsius
      cout << fahrenheit << " Fahrenheit = "<< fixed << setprecision(2)<< celsius << " Celsius"<<endl<<endl ;//displays the double .00
      break; //same for f and F
    case 'C':
    case 'c'://celsius
      cout << "Enter a temperature in Celsius: ";
      cin >> celsius; //entered temperature to be converted
      
      fahrenheit=(double) (celsius*9)/5+32;//conversion from celsius to fahrenheit
      cout << celsius << " Celsius = "<<fixed<<setprecision(2)<< fahrenheit << " Fahrenheit"<<endl<<endl; //displays the double 0.00
      break;//for all cesius

    default :      
      cout << "Invalid choice"<<endl; //for all values entered that arent f,F,c C
  
    }
      return 0;
    }

