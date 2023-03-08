/*****************************************************************************
Reinier Swanepoel
CS111
03-20-20

getInt asks for an integer and rejects bad inputs outside the range.
getDouble asks for a decimal number and rejects bad inputs outside the range.
getYN asks for Y or N and reject bad inputs other than Y, y, N or n.
*****************************************************************************/
#include <iostream>
using namespace std;

/******************************************************************************   
getInt:
min is the minimum value accepted                                                                                                             
max is the maxmum value accepted                                                                                                             
msg is the message shown when the user's input was outside the range.               
This function will read an integer number and keeps asking to enter a new number as long as the user enters a number outside the range. It will return a number 
within the range (between min and max inclusive).                                 *******************************************************************************/
int getInt(int min, int max, string msg) //msg for error
{
  int n; //user's input
  cin >> n;
  
  while(n < min || n > max) // the user's input was outside the range //or
    {
      cout <<msg;  //show the message to the user //error
      cin >> n;     //read a new input
    }
  
  return n; //return a good value that is within the range (between min and max enclusive)
}

/******************************************************************************   
getDouble:
min is the minimum value accepted                                                

max is the maxmum value accepted                                                 

msg is the message shown when the user's input was outside the range.            

This function will read an decimal number(gpa) and keeps asking to enter a new number as long as the user enters a number outside the range. It will return a number
within the range (0.00 - 4.00).
*******************************************************************************/
double getDouble(double min, double max, string msg) //list data type            
{
  double gpa; //user's input
  cin >> gpa;
  
  while(gpa < min || gpa > max) // the user's input was outside the range //or
    {
      cout <<msg;  //show the message to the user //error
      cin >> gpa;     //read a new input
    }
  return gpa; //the function return gpa
}
/******************************************************************************   char Y is for the answer yes

char N is for the answer no                                                            
msg is the message shown when the user inputs a character other than Y, y, N or N.
This function will read an answer from the user and if lowercase it will convert to uppercase. reject all other answers
*******************************************************************************/

char getYN(char Y, char N,string msg)
{
  const int OFFSET = 32; //use same data types
  char answer; //char x
  cin>> answer;  
  //while not the answer were looking for, stay in loop
  while(answer!= 'Y' && answer != 'N'&& answer != 'y' && answer != 'n')  
    {
      cout<<msg;
      cin>>answer;
    }
  if(answer == 'y' || answer == 'n') //if correct options then check and convert
    answer=answer - OFFSET;
  else if (answer == 'Y' || answer =='N')
    answer=answer;
  
  return answer;
}
/*
As long as the user enters characters other than Y, y, N, or n, keep asking. If the user enters a lowercase y or n, convert it to the uppercase Y or N. //if lowercase add 32 so caps only
This function returns either uppercase Y or N.
*/

