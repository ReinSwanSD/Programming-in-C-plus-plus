/*******

Reinier Swanepoel
3/9/2020
Military Function 

This program will verify the eligibility of joining the military from the
user’s gender and age. Make the following 4 functions in addition to the main.

*********/


#include <iostream>
using namespace std;

//prototypes
void showProgInfo();
void getInfo (string& name, char& gender, int& age);
void printInfo (string name, char gender, int age);
bool verifyEligibility (char gender,  int age);
void printInfo (bool eligibility, string name);


int main()
{ 

//variables
  char gender; //m or f
  int age; //any number above 0
  string name; //string name first
  bool eligibility; //true or false


  showProgInfo();
  
  getInfo(name,gender,age);
  
  eligibility = verifyEligibility (gender, age);
 
  printInfo (eligibility, name);



  return 0;
}


/******

this is the program instructions

******/

void showProgInfo()
{
  
  cout<< "****************************************************"<<endl;
  
  cout<< "This program will tell you if you are eligible to join the military." <<endl;
  
  cout<< "****************************************************" <<endl;
  
}

/******
this will get info from the user

******/

void getInfo (string& name, char& gender, int& age)
{

  cout<< "Enter first name: "; //name is first only
  cin>> name;

  cout<< "Enter gender: "; //m or f
  cin>> gender;

  cout<< "Enter age: "; //any number
  cin>>age;

}

/*****

This will check if the entered information is eligibble

******/

bool verifyEligibility (char gender,  int age)
{
  bool eligibility; //true and false
  
  if(gender== 'm' || gender== 'M')
    
    if(age>=18)
      eligibility = true; //true =1
    else
      eligibility = false; //false =0
  else
    eligibility = false;
  
  return eligibility; //return true or false   
}

/*****

this will display all the correct info if they are eligible or not

******/

void printInfo (bool eligibility,string name)
{
  
  if(eligibility==true)//if eligible
    cout << "Dear " << name << " Please consider joining the military" << endl;
  else
    cout << "Thank you for applying." << endl; //if not eligible
 

}
