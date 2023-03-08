/***************************************************************

Reinier Swanepoel
RationalNumbers,cpp

Will take the following two fractions and add them up and simply them into one single fraction

**************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <stdlib.h>


using namespace std;

struct ratNum
{
  int nrm;//numerator                                                                                                                            
  int den;//denominator                                                                                                                          
};


//function prototypes

//????????  fill
void fillRatNum (ratNum&n);

//????????  add
ratNum add2RatNum(const ratNum ratNum1,const ratNum ratNum2);
//????????  print
void printEquation(ratNum ratNum1, ratNum ratNum2, ratNum ratNum3);

//????????  simplify
ratNum simplifyRatNum(ratNum&n);

//this is where you declare the struct for rational numbers
int main()
{
  //data types

  ratNum ratNum1; //first rational number
  ratNum ratNum2; //second rational numbers following the structure of numerator and denominator
  ratNum ratNum3; //sum of both
  //call fillRatNum
  cout<<"Rational Number 1";
  fillRatNum(ratNum1); //fill first rational number
  cout<<"Rational Number 2";
  fillRatNum(ratNum2); //fill second rational number
  cout<<endl;

  //call add2RatNum

  ratNum3=add2RatNum(ratNum1,ratNum2);
  

  //call printEquation

  printEquation(ratNum1, ratNum2, ratNum3);




  /*
    cout << ?????? << endl; //show top 
    cout << ?????? << endl; //show --------- 
    cout << ?????? << endl; //show bottom
  */


  cout<<endl;
  return 0;
}

/****************************************

function that fill one rational number complete fraction

will ask for two numbers, the numerator and denominator

****************************************/


void fillRatNum(ratNum&n)
{
cout<<"\n\tEnter the top number: ";
cin>>n.nrm;


cout<<"\tEnter the bottom number: ";
cin>>n.den;

}




/**************************************

function that will recieve the 2 rational numbers from main and 
add them both and 
return a ratNum that has the sum of these

if simplify function works, call it inside here to simplify sum
**************************************/

ratNum add2RatNum(const ratNum ratNum1,const ratNum ratNum2)
{
  ratNum ratNum3;

  ratNum3.den=(ratNum1.den)*(ratNum2.den);
  
  ratNum3.nrm=((ratNum1.nrm)*(ratNum2.den))+((ratNum2.nrm)*(ratNum1.den));

  simplifyRatNum(ratNum3);

  return ratNum3;
}

/*****************************************
 
function that will print the original rational numbers and the sum and display the equation

****************************************/

void printEquation(const ratNum ratNum1,const  ratNum ratNum2,const  ratNum ratNum3)
{
  cout<<fixed;

  //if answer doesnt end in whole number
  cout<<setw(4)<<right<<ratNum1.nrm<<" "<<setw(3)<<"   "<<setw(4)<<right<<ratNum2.nrm<<" "<<setw(3)<<"   "<<setw(4)<<right<<ratNum3.nrm<<" "<<endl;

  cout<<setw(5)<<"-----"<< setw(3)<<" + "<<setw(5)<<"-----"<<setw(3)<<" = "<<setw(5)<<"-----"<<endl;

  cout<<setw(4)<<right<<ratNum1.den<<" "<<setw(3)<<"   "<<setw(4)<<right<<ratNum2.den<<" "<<setw(3)<<"   "<<setw(4)<<right<<ratNum3.den<<" "<<endl;
  //else if number is a whole number, dont show 1 as denomerator
}

/*****************************************

function that will simplify any rational number to its simplest form

*****************************************/

ratNum simplifyRatNum(ratNum&n)
{
  int count=7;
  ratNum simp;
  
  do
   { 
     count--;
     simp.nrm=n.nrm % count;
     simp.den=n.den % count;
   }while(simp.nrm != 0, simp.den !=0);
    
  simp.nrm=count;
  simp.den=count;
  

  return simp;


}






















