/*******

Reinier Swanepoel
3/10/2020
Random Number Guessing Game

Write a program that generates a random number between 1 and 100 and asks the user to guess what the
number is. If the user's guess is higher than the random number, the program should display “Too high, try
again”. If the user’s guess is lower than the random number, the program should display “Too low, try
again”. The program should use a loop that repeats until the user correctly guesses the random number. 

******/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  srand(time(0)); //as stated in directions
  int num;//random num
  int guess=0;//guess

  num = rand() % 100 + 1; //generate random
  
  cout<< "Guess a number between 1 and 100. Enter your guess: ";
  cin>> guess; //first guess 1-100
  
  while (guess!=num)//while you guess it wrong
    {
      if(guess>num)//tell you how close
	cout<<'\t'<< "Too high, try again."<<endl; //lower
      else
	cout<<'\t'<< "Too low, try again."<<endl; //higher

      cout<< "Enter your guess: ";
      cin>> guess;//repeat with same number
    }

  cout<< "You guessed it right!"<<endl; //end game or ask to repeat
  cout<<endl;
  return 0;
}

