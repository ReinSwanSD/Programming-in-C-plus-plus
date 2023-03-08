/********
	 
	 Reinier Swanepoel
	 
	 This function will calculate b^e and return the answer.
	 
	 for each parameter:
	 
	 b is the base
	 e is the exponent
*******/


#include <iomanip> //needed
#include <iostream>
using namespace std;


int pow(int b, int e) //b is for base, e is for exponenet
{    
  int ans = 1; //answer is an int
  
  for( int i = 1; i<= e; i++)
    ans *= b; //answer=answer*b and answer =1
  
  return ans; //the value to be stored
  
}
/********
	 This function will take double num and if its negative it will multiply by -1, if postive it will keep the same
	 
	 num is decimal number, postive or negative
	 
*****************************************/

double fabs(double num) //same kind of thing
{  
  if (num<0) //if negative
    
    num=num*-1.0; //math
  //num*=-1
  else //if positive
    
    num=num; //same answer
  
  return num; //store this value
  
}

/********
	 
	 This function will take double num and add .5 to it then convert it to an int
	 
	 num is decimal that adds .5 and drops of the decimal because its converted into a int
	 
********/
int round(double num ) //round the double and make it an int
{
  int roundedNum; //declare variable
  roundedNum=num+.5; //round math
  
  return roundedNum; //store answer
}
