/***************************************************************************
CS211
Template prepared by Kazumi Slott 
Your name: Reinier Swanepoel

Program description:convert a decimal number to binary, octal, or hexadecimal

***************************************************************************/
#include <iostream>
#include <string>
#include "stack.h"
#include <cstdlib>
#include <iomanip>

using namespace std;

#include "/cs/slott/cs211/checkInput.h"

//prototypes
int getBase();
char convertToChar(int n);
void convertRec(int n, int b);
void convertStack(int n, int b);

int main()
{
  int dec;
  int base;

  cout << "Enter a number in base 10: ";
  
  //get a decimal number by calling getData in checkInput.h. Accept a numer 
  //between 1 and 999999.
  dec=getData(1,999999, "Invalid Number, try between 1 and 999999: ");

  //get a base (2, 8 or 16) by calling getBase
  base=getBase();

  cout << "----------- Using recursion ---------------" << endl;
  //call convertRec to show the number in the base number system of the user’s choice
  convertRec(dec,base);

  cout << endl;

  cout << "----------- Using a stack ---------------" << endl;
  //Call convertStack to show the number in the base number system of the user’s choice
  convertStack(dec,base);

  cout << endl;
  return 0;
}

/****************************************************************************
This function asks for a number system to which a decimal number is converted, either 2, 8 or 16.
It rejects bad inputs other than 2, 8 or 16.
It returns either 2, 8 or 16
****************************************************************************/
int getBase()
{
  int response;
  
  cout<<"Enter a base to convert (2,8,16): ";
  cin>>response;
  
      while(response!=2 && response!=8 && response!=16)    
	{
	  cout << "Base Must be 2, 8, or 16: ";
	  cin >> response;
	}
      
      return response;
}

/****************************************************************************
This function receives an integer between 0 and 15 and returns the character.
If n = 0 .. 9, it returns '0' .. '9'
If n = 10 .. 15, returns 'A' .. 'F'

n is an integer between 0 and 15
****************************************************************************/
char convertToChar(int n)
{
  if (n>=0 && n<=9)
    {
      char c = (char)n + '0';
      return c;
    }
  //char 49='1';
  if (n>=10 && n<=15)
    {
      char c = (char)n + '7';
      return c;
    }
  //char 65='A','7'= int 55
}

/***************************************************************************
This is a <<recursive>> function to convert a decimal number to a different number system and print it.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
***************************************************************************/
void convertRec(int n, int b)
{
  if (n == 0)
    {
      return;
    }
  else
    {
      convertRec(n/b,b);
      cout << convertToChar(n%b);
    }
 
}

/**************************************************************************
This function uses a stack to convert a decimal number to a different number system and prints it.
This is not a recursive function.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
**************************************************************************/
void convertStack(int n, int b)
{
  Stack s;
  
  while(n > 0)
    {
      char c= convertToChar(n%b);
      n=n/b;
      s.push(c);
    }
  
  while( !s.isEmpty() )
    cout<<s.pop();
  cout<<endl;
}
