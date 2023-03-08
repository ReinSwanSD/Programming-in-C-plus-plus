/********

Reinier Swanepoel
3/11/2020
Math Quiz 

ask student to answer simple math questions

******/

#include <iostream>
#include<cstdlib>
using namespace std;

int main()
{
  srand(time(0)); //needed for all random generators
  
  int questions; //how many questions do u want to solve
  int equation; //answer to num1 and num2
  int answer;//your guess
  int num1; //rand1
  int num2; //rand2
  int correct=0;//add 1 if right
  int incorrect=0; //add 1 if wrong
  int count=0;//count every time

  cout<< "How many questions do you want to solve? "; //amount of questions to asnwer
  cin>> questions;

  while (count<questions)//start at 1 and less than the question
    {
      count++;//add 1 count
    }
  for(int i=1; i<=questions;i++) //for each question generate a new question
    {
      num1=(rand() % 10);//random
      num2= (rand() % 10); //random
      equation=num1+num2; //answer
      
      cout<<endl; 
      cout<< num1 << " + " <<num2<< " = ";
      cin >> answer;
      cout<<endl;
      if (answer==equation)
	{
	  cout<<'\t'<<"Good job"<<endl; //tab line and display correct
	  correct++; //add 1 to count
	}
      else
	{
	  cout << '\t' <<  "Correct answer is " << equation<<endl;
	  incorrect++; //add 1 to count
	} 
    }
  
  cout<< "You answered " << correct << " questions correctly and " << incorrect << " questions incorrectly."<<endl; //final answer
  
  return 0;
}
