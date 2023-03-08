/***************************

Reinier Swanepoel
Fibonacci Lab

Create a recursive function that will calc a fibonacci number at a specific position
Create a non recursive solution that will calc a fibonacci number at a speicific position
Compare the run times between the recursive and non recursive solutions

***************************/

#include <iostream>
#include <time.h>
using namespace std;
#include "/cs/slott/cs211/checkInput.h"

//prototypes
int fib(int num);
int recursiveFib(int pos);


int main()
{
  
  int pos,sum;
  clock_t start, end;
  cout << "Enter a position: ";
  pos = getData(0, 46, "Invalid input. Please enter a position between 0 and 46");
  
  start = clock();
  
  sum = fib(pos);
  
  end = clock();
  
  cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
  cout << "Fibonnaci number at position " << pos << " is " << sum << endl;
  
  start = clock();
  
  sum = recursiveFib(pos);
    
  end = clock();

  cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
  cout << "Fibonnaci number at position " << pos << " is " << sum << endl;
    
  return 0;

}

/**************

function that is non recursive solution for fibonacci number

*************/

int fib(int num)
{
  int n1 = 0, n2 = 1;
  int fibnum = 0;
    
  if (num <= 1) 
    {
      return num;
    }
  else
    {
      for (int i = 0; i < num-1; i++)
	{
	  fibnum = n1 + n2;
	  n1 = n2;
	  n2 = fibnum;
	  
	}
    }
  return fibnum;
}
/*********************

function that is recursive solution for fibonacci number

**********************/
int recursiveFib(int pos)
{
  if(pos <= 1) //position is 0 or 1 (base cases)
    return pos;
  else
    return recursiveFib(pos-2) + recursiveFib(pos-1);
}
