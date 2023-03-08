/*****

Reinier Swanepoel
3/27/2020
Craps Statistics of Game

Create a game of craps using dice and random numbers
You are going to calculate the probabilities of winning and losing in the craps game.

******/
//header
#include<iostream>
#include<iomanip>
#include<cstdlib> //for random number generator
#include"input.h"  //include input.h
#include<stdlib.h>

using namespace std;




//global variables
//data
int secondRoll; //first roll
int firstRoll; //second roll
int size;//total amount of games the user wants to play
double winP=0.00;
double loseP=0.00;

//
int rolldice(); //function for rolldice
bool playGame();
int main() //main function
{
  srand(time(0));  //needed for random
  //data
  // int secondRoll; //first roll
  // int firstRoll; //second roll
  // int size;//total amount of games the user wants to play
  // double winP=0.00;
  // double loseP=0.00;

  // ask the user
  cout<<"How many games do you want to play? ";
  size= getInt(1,100000000, "You need to input a number between 1 and 100000000: ");
  
  for (int i=0;i<size; i++)
    {
      if(playGame()== true)
	winP= winP + 1.00;
      else
	loseP= loseP + 1.00;

    }

 
  //  winP = (winP / size) * 100;

  //  loseP = (loseP / size) * 100;

  //Display the result.

  cout<<"\twin %\tlose %"<<endl;

  cout<<fixed<<setprecision(3)<<"\t"<<(((double)(winP*100))/(size))<<"\t"<<fixed<<setprecision(3)<<(((double)(loseP*100))/(size))<<endl;

  return 0;
}



/****

This function will random generate a dice ammount

****/

int rolldice() //function for rolldice
{
  int roll;
  roll= (rand() % 6 +1) + (rand()%6+1); //random the dice

  return roll; //return number
}



/*******

This function will play a complete game of craps

*******/


bool playGame()
{

        //
      firstRoll=rolldice(); //make dice equal
      
  //  cout<< firstRoll << endl; //output dice roll for first roll
      
      if(firstRoll==11||firstRoll==7)
	//	winP= winP + 1.00;
      return true;
      //  cout<<"====Win====="<<endl;  //win if 7 or 11
      else if(firstRoll==2 || firstRoll==3 || firstRoll==12)  //lose if 2,3,12
	//	loseP=loseP + 1.00;
      return false;
      //  cout<<"=====Lose====="<<endl;
      else
	{
	  do{  //if second hand
	    secondRoll=rolldice();
	    //cout<<secondRoll<<endl;
	  }while(secondRoll != 7 && secondRoll != firstRoll);//if the dice is 7 or eq\ual to first roll win
	  
	  if(secondRoll==7) //if second 7 is win
//	    loseP=loseP + 1.00;
	  return false;
//      cout<<"=====Lose====="<<endl;
	  else //if not 7 than lose
	    //	    winP= winP + 1.00;
	  return true;
//      cout<<"=====Win====="<<endl;
	}
}
