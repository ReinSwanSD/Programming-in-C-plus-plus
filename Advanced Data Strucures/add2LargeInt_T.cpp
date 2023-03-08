/****************                                                                                                                                         
Reinier Swanepoel
CS211
kazumi slott
                                                                                                                                               
Homework: lqueue add 2 int                                                                       
This  program that will add 2 large positive integer numbers that are too big for the long (longer version of                                                                              
int) data type.                                                                                                                                           
                                                                                                                                                          
********************/
#include <iomanip>
#include "LL_T.h"
using namespace std;

//prototypes
void createReverse(LL<int>& l, string& n);
void addLLs(LL<int>& l1, LL<int>& l2, LL<int>& t);

int main()
{
  LL<int> l1; //first num
  LL<int> l2; //second num
  LL<int> total; //sum
  string n1; //user input 1
  string n2; //user input 2


  cout << "Enter the first number: ";
  cin >> n1;
  cout << "Enter the second number: ";
  cin >> n2;
  cout << endl;


  createReverse(l1, n1);
  createReverse(l2, n2);


  l1.displayAll(); //display reversed sequence, l1
  cout << " + ";
  l2.displayAll(); //display reversed sequence, l2
  cout << " = ";
  addLLs(l1, l2, total); //calculates sum
  total.displayAll(); //displays reversed sum
  cout << endl;


  cout << n1 << " + " << n2 << " = ";
  total.printAllReverse();
  cout << endl;

  return 0;
}

/*****************************************
createReverse()
uses addRear() to add each digit to a linked list in reverse order (starting from the last nnumber in the string). The funtion takes a char from the string, converts it to int, then adds it to the linked list.

*****************************************/
void createReverse(LL<int>& l, string& s)
{
  int char_to_int;
  for(int i = s.length()-1; i >= 0; i--)
    { //s.length()-1 makes it start at the last index of the string 
      char_to_int = s[i]-48; //converts char to int
      l.addRear(char_to_int); //adds to LL
    }
}

/*****************************************
addLLs()
Adds the digits together to create the sum.

*****************************************/
void addLLs(LL<int>& l1, LL<int>& l2, LL<int>& t)
{
  int op1, op2, sum;
  bool over_nine = false;

  while (!l1.isEmpty() || !l2.isEmpty())
    {
      
      if (l1.isEmpty())
	{ //l2 has more digits than l1, so op1 becomes imaginary 0
	  op1 = 0;
	}
      else 
	{
	  op1 = l1.deleteFront();
	}
      
      if (l2.isEmpty())
	{ //l1 has more digits than l2, so op2 becomes imaginary 0
	  op2 = 0;
	}
      else 
	{
	op2 = l2.deleteFront();
	}
      
      sum = op1 + op2; 
      
      if (over_nine == true)
	{
	sum++;
	}
      
      if (sum > 9)
	{
	  sum-=10;
	  over_nine = true;
	}
      else
	{
	  over_nine = false;
	} 
      
      t.addRear(sum);
  }
  
  if (over_nine == true)
    {
      t.addRear(1);
    }
}
