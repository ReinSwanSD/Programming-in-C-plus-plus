/*********************

Reinier Swanepoel
3/23/2020

Array lab without functions.

This program will declare a const SIZE to 50 integers and create 3 for loops
and print the results for even and off count.

*********************/

#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  //variables
  srand(time(0));
  const int SIZE=50; //const for size
  int ar[SIZE];
  int even=0; //count for even
  int odd=0; //count for odd
  //this for loop will fill the array with random numbers between 1 and 50
  for(int i=0;i<SIZE;i++)
    {
      ar[i]=rand()%50+1; //only 1-50
    }

  cout<<"\n Here is the list of random numbers." <<endl;
  // this for loop will display the arrays content
  for(int i=0;i<SIZE;i++)
    {
      cout<<i+1<<":"<< ar[i]<<endl; //1:, 2:, 3:,
    }
  //this for loop will count the even and odd numbers
  for(int i=0; i<SIZE; i++)
    {
      if (ar[i] % 2==0) //odd= even-50
	even++;
      else // or count odd++
	odd++;
    }//odd+even=SIZE(50)
  
  cout<<"Even numbers : "<<even << endl; //display total
  cout<<"Odd numbers : "<<odd <<endl;
  
  return 0;
}
