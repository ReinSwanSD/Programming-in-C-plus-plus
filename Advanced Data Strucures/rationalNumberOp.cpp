/********************************************
Template created by Kazumi Slott
CS211
Date:2/21/21
Your name:Reinier Swanepoel
Description of your program:Will grab two rational numbers from the user and add them
********************************************/
#include <iostream>
using namespace std;
#include "array.h"  //This is your array.h

struct rNum
{
  int top; //numrator
  int bot; //denominator
};
//prototypes
ostream& operator<<(ostream& os, const rNum& n); //overloading used for cin
istream& operator>>(istream& is, rNum & n); //overloading used for cout
rNum operator+/*addRationalNumbers*/(const rNum& n1, const rNum& n2); //adding rational numbers
void simplify(rNum& n); //simplify function
rNum operator+=/*addRationalNumbers*/(rNum& n1, const rNum& n2); //adding rational numbers
bool operator > (const rNum& n1, const rNum& n2); //overload for sort function
bool operator==(rNum&n1, rNum&key); //overload for find function

int main()
{
  rNum n1;//first rat num
  rNum n2; //second rat num
  rNum ans; //answer of both rat nums

  cout << "\n-------------- 1 -----------------" << endl;
  cout << "Rational Number 1";
  cin >> n1; //overload
  
  cout << "n1 is " << n1 << endl; //overload
  
  cout << "\n-------------- 2 -----------------" << endl;
  cout << "\nRational Number 2";
  cin >> n2;
  
  cout << "n2 is " << n2 << endl; 
  
  cout << "\n-------------- 3 -----------------" << endl;
  ans = n1 + n2;

  cout << n1 << " + " << n2 << " = " << ans << endl;
  
  cout << "\n-------------- 4 -----------------" << endl;
  const int SIZE = 3; //MAX size
  //Declare an array of rNums that has SIZE slots
  rNum  rNums[SIZE];//array of rat nums
 
  //fill the array by calling fill() in your array.h
  fillArray(rNums,SIZE);
  
  cout << "Checking to see if the array is filled" << endl;
  //print the array by calling print() in your array.h
  printArray(rNums,SIZE);
  cout<<endl;
  cout << "\n-------------- 5 -----------------" << endl;
  //sort the array in ascending order by calling sort() in your array.h
  sort(rNums,SIZE); //overload

  cout << "Checking to see if the array is sorted in ascending order" << endl;
  //print the array by calling print() in your array.h
  printArray(rNums,SIZE); 

  cout << "\n-------------- 6 -----------------" << endl;
  cout << "Checking to see if " << n1 << " is in the array " << endl;
  //Call find() in your array.h to see if n1 exists in the array. Say found or not found. See #6 in the test runs in the hw document.   
  int found=find(rNums,SIZE, n1);//overload
  if(found!=-1)
    cout<<n1<<" is found."<<endl;
  else
    cout<<n1<<" is not found."<<endl;

  cout << "\n-------------- 7 -----------------" << endl;
  cout << "n1 is " << n1 << " n2 is " << n2 << " before n1 += n2" << endl;
  n1 += n2; //n1=n1+n2
  //make operator overloading^
  cout << "After n1 += n2, n1 is " << n1 << endl << endl;
  
  return 0;
}

/******************************

n is a rational number in the caller

this function will simplify n

******************************/
void simplify(rNum& n)
{
  bool found=false;
  int start;
  // start looking for the GCD from the smallest number between top and bottom
  if (n.top<n.bot)
    start=n.top;//start from top
  else
    start =n.bot;//start from bottom
  //look for GCD
  for( int div=start; !found && div>=1; div--)
    if(n.top%div==0 && n.bot%div == 0)
    {
      found=true; //found the GCD
      n.top=n.top/div;
      n.bot=n.bot/div;
    }

}


/******************************************
Create operator overloading functions so the above main runs.
You need to figure out what you need to make.
*******************************************/

/***********
This  function is for the cin reading

is is for cin
n is for n1
***********/
istream& operator>>(istream& is, rNum & n)
{
  cout<<endl;
  cout<<"\tEnter the top number: ";
  is>>n.top;
  cout<<"\tEnter the bottom number: ";
  is>>n.bot;

}
/*************
This function is for the cout operator

os is for cout
n is for the rational number
***********/
ostream& operator<<(ostream& os, const rNum& n)
{
  os << n.top <<"/"<<n.bot;
  return os;
}
/**********
This function will add two rational numbers and will return the ans
use simplify function in here.
**********/

rNum operator+/*addRationalNumbers*/(const rNum& n1, const rNum& n2)
{
  rNum ans;
  ans.top = n1.top * n2.bot + n2.top * n1.bot;
  ans.bot = n1.bot * n2.bot;
  simplify(ans);
  return ans;
}
rNum operator+=/*addRationalNumbers*/(rNum& n1, const rNum& n2)
{
  rNum ans;
  n1.top = n1.top * n2.bot + n2.top * n1.bot;
  n1.bot = n1.bot * n2.bot;
  simplify(n1);
  return n1;
}



/*********

This function will overload the sort function so it can sort the rat num is order

***********/

bool operator > (const rNum& n1, const rNum& n2)
{
  int x= n1.top * n2.bot;
  int y= n2.top * n1.bot;
  if(x>y)
    return true;
  else
    return false;
}

/**********

This function will find the searched key in the array and tell you if it in is the array or not

**********/
bool operator==(rNum&n1, rNum&key)
{
  if(n1.top==key.top && n1.bot==key.bot)
    return true;
  else
    return false;
}
