/*******

Reinier Swanepoel
CS111
2/17/2020

Grade

Make a program that will ask the user for a grade (A, B, C, D or F) and display one of the messages depending on the grade.   If the grade is an A or B, display “Good job”.   If the grade is a C, display “OK”   If the grade is a D or F, display “Work harder”. For any other letter (the user entered a letter other than an A, B, C, D or F), display “Invalid grade”.

*******/

#include <iostream> //default to start
using namespace std; //so we dont have to put it on every line

int main () // code starts
{ //memorise this so you dont have to look at notes

  //inputs first

  char grade; //only variable
  bool pass=false; // false = 0
  //or
  //bool pass;
  //pass=false;

  cout << "Enter a grade."<< endl; //ask user for grade
  cin >> grade; //entered value

  //algo

  if (grade == 'A' || grade  == 'B') //first if
    {
      cout << "Good job"<<endl; //<<"Congratulations! You passed the class."<<endl;
    pass=true;
    }
  else  if  (grade == 'C') //second if
    {
      cout << "OK"<<endl; //<<"Congratulations! You passed the class."<<endl;
    pass=true;
    }
  else  if (grade == 'D' || grade == 'F') //third if
    {
    cout << "Work harder"<<endl;
    //pass=false already so dont need to enter it
    }

  //  if (grade != 'A', 'B' , 'C' ,'D', 'F') //forth if
  // cout << "Invalid grade"<<endl;// multiple ways of doing this

  else
    cout<< "invalid grade"<<endl;


  if (pass==true)
    cout << "Congratulations! You passed the class."<<endl;













  return 0; //default to finish a program
}
