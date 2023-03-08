/*****************************************************************
Reinier Swanepoel
CS111
Template prepared by Kazumi Slott
4/8/2020
Lab on 2D arrays
*****************************************************************/ 
#include <iostream>
#include <iomanip>
using namespace std;

//declare 2 constants for the sizes of the 2 dimensional array
const int NUM_STU = 5; //5 colloums
const int NUM_TEST = 3; //3 rows

//???????? Where does the prototype for showTable() go?
void fillArray(int scores[][NUM_TEST]);
void showTable(const int scores[][NUM_TEST]);



int main()
{
  //declare the 2 dimensional array and initialize the array using the initialization list
  int scores[NUM_STU][NUM_TEST];
  fillArray(scores);

  //????????? Call showTable here
  showTable(scores);  

  return 0;
}

void showTable(const int scores[][NUM_TEST])
{
  double average;
  double total=0;
  //  int counter=0;
  //Show the lables for the table
  cout << setw(10) << "Test#" << setw(10) << "Stu 1" << setw(10) << "Stu 2" << setw(10) << "Stu 3" << setw(10) << "Stu 4" << setw(10) << "Stu 5" << setw(10) << "Average" << endl;

  //????????? Show the table using a nested for loop here

  for(int test=0; test<NUM_TEST; test++)
    {
      cout<<setw(10) <<  test+1; //displays test number starting with 1 to 3
      
      for(int stu=0; stu<NUM_STU; stu++)
	{
	  cout<< setw(10)<<scores[stu][test]; //display score
	  total=total+scores[stu][test]; //add to total

	  average=double(total/5); //find average

	  //	  counter=counter+1; //after 5 scores find average
	  
	  if(stu==4) //after 5 scores find average
	    {
	      cout <<fixed<<setprecision(1);
	      cout<<setw(10)<<average;
              cout<<endl;
	      //instead of counter use stu
	      //	      counter=0;
	      total=0;

	    }
	  
	}
     
    }
  
  cout<< setw(10) << "Average";
  for(int stu = 0; stu < NUM_STU; stu++)
    {
      total = 0;
      for(int test = 0; test < NUM_TEST; test++)
	total += scores[stu][test];
      cout << setw(10) << fixed << setprecision(1) << (double)total/NUM_TEST;
    }
  cout << endl << endl;
}
void fillArray(int scores[][NUM_TEST])
{
  for(int test = 0; test < NUM_TEST; test++)
    {
      cout << "Enter scores for Test # " << (test + 1) <<endl;
      for(int stu = 0;stu < NUM_STU; stu++)
	{
	  cout<<"\t Student #"<< stu +1 <<": ";
	  cin >> scores[stu][test];
	  cout<<endl;
	}

    }
}
