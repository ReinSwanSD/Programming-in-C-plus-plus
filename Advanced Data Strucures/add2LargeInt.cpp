/****************                                                                                                    
Reinier Swanepoel                                                                                                       CS211                                                                                                                   Kazumi Slott                                                                                                             
Homework: lqueue add 2 int                                                                                              This  program that will add 2 large positive integer numbers that are too big for the long (longer version of
int) data type.
                          
********************/
#include <iomanip> //used for fixed                                                                                     
#include <iostream>
#include <cstdlib> //for atoi() <-- may not use this
#include "lqueue.h"

using namespace std;

//prototypes
void createReverse(LQueue& l, string& n);
void addLLs(LQueue& l1, LQueue& l2, LQueue& t);

//main
int main()
{
  //variables for two entered numbers
  string n1; //user input 1

  string n2; //user input 2
  
  //ask user to enter two numbers
  cout << "Enter the first number: ";
  cin >> n1;

  cout << "Enter the second number: ";
  cin >> n2;
  cout << endl; //proper spacing
  
  // create the lqueue
  LQueue l1; //first num                   
  
  LQueue l2; //second num                                                                                                
  LQueue total; //total of first and second
  
  //create list of the numbers in reverse, named the lqueue
  createReverse(l1, n1);//reversing first entry
  createReverse(l2, n2); //reversing second entry

  //call and print reversed answer
  l1.displayAll(); //display reversed n1, l1
  cout << " + ";
  l2.displayAll(); //display reversed n2, l2
  cout << " = ";
  addLLs(l1, l2, total); //calculates sum
  total.displayAll(); //displays reversed sum
  cout << endl; //proper spacing

  // correct equation
  cout << n1 << " + " << n2 << " = ";
  total.printAllReverse();
  cout << endl << endl;

  return 0;
}

/*****************************************
Function: createReverse()

Purpose: creates the lqueue from strings
char_to_int (int) converts the char into int linked list.
*****************************************/
void createReverse(LQueue& l, string& s)
{
  int char_to_int; //int conversion

  for(int i = s.length()-1; i >= 0; i--)
    { //start at the last index of the string 
      char_to_int = s[i]-48; //converts char to int
      l.addRear(char_to_int); //adds to LL
    }
}

/*****************************************
Function:addLLs()

Purpose:Adds the digits together to create the sum.
carry over = carry over
op1  is the first number to be added.
op2  is the second number to be added
sum  sum of op1 and op2, gets added to LL
*****************************************/
void addLLs(LQueue& l1, LQueue& l2, LQueue& t)
{
  int op1, op2, sum;
  bool carry_over = false;
  
  // adding function
  while (!l1.isEmpty() || !l2.isEmpty())
    {
      // l1
      if (l1.isEmpty())
	{ //l2 has more digits than l1, so op1 becomes imaginary 0
	  op1 = 0;
	}
      else 
	{
	  op1 = l1.deleteFront();
	}
      // l2
      if (l2.isEmpty())
	{ //l1 has more digits than l2, so op2 becomes imaginary 0
	  op2 = 0;
	}
      else 
	{
	  op2 = l2.deleteFront();
	}

      // add 
      sum = op1 + op2; 

      //carry the one
      if (carry_over == true)
	{
	  sum++;
	}
      
      if (sum > 9)
	{
	  sum-=10;
	  carry_over = true;
	}
      else
	{
	  carry_over = false;
	} 
      // Add to the total 
      t.addRear(sum);
  }
  // the last 1 must be carried 
  if (carry_over == true)
    {
      t.addRear(1);
    }
}

