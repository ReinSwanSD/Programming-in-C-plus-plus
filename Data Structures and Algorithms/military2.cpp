
/*******

Reinier Swanepoel
CS111
2/17/2020
Military

Make a program that will display one of the messages below depending on the gender and age the user enters. 

*******/

#include <iostream> //intro for any code
using namespace std; //instead of typing on everyline

int main () //start code
{ //variables
  char gender;//either one character
  int age; //any integer
  int wait; //used to calc age needed to wait

  cout << "Enter a gender."<<endl; //ask for gender
  cin >> gender; //given


  if (gender=='m' || gender=='M') //if you are a male enter the loop
    {
      cout << "Enter an age." << endl; //ask for age
      cin >> age; //given

      if (age <= 0) //has to be valid age
	{
	  cout << "Invalid age."<<endl;
	}
      else if (age <= 16) //cant be a minor
	{
	  wait = 17 - age;
	  cout << "You need to wait " << wait << " more years."<<endl;
	}
      else if (age >= 17 && age <= 42) // adult age is perfect
	{
	  cout << "The military is hiring more people like you."<<endl;
	}
      else //if(age >= 43) //men
	{
	  cout << "Thank you for using the system." << endl;
        }
    }
  else if (gender == 'f' || gender == 'F')  //if you are not male
    cout << "Thank you for using the system, but we were only looking for men." <<endl;


  else  //if you are not male or female
    cout << "Invalid gender" <<endl;

      return 0;
}
