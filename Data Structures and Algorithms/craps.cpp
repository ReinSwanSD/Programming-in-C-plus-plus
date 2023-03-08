/*****

Reinier Swanepoel
3/10/2020
Craps Game

Create a game of craps using dice and random numbers

******/

#include<iostream>
#include<cstdlib> //for random number generator
using namespace std;

/****
     
     This function will random generate a dice ammount
     
****/

int rolldice() //function for rolldice
{
  int roll;
  roll= (rand() % 6 +1) + (rand()%6+1); //random the dice
  
  return roll; //return number
}



int main() //main function
{
  srand(time(0));  //needed for random
  int secondRoll; //first roll
  int firstRoll; //second roll
  firstRoll=rolldice(); //make dice equal

  cout<< firstRoll << endl; //output dice roll for first roll
  
  if(firstRoll==11||firstRoll==7)	
    cout<<"====Win====="<<endl;  //win if 7 or 11
  else if(firstRoll==2 || firstRoll==3 || firstRoll==12)  //lose if 2,3,12
    cout<<"=====Lose====="<<endl;
  else
    {
      do{  //if second hand
	secondRoll=rolldice(); 
	cout<<secondRoll<<endl;
      }while(secondRoll != 7 && secondRoll != firstRoll);//if the dice is 7 or equal to first roll win
      
      if(secondRoll==7) //if second 7 is win
	cout<<"=====Lose====="<<endl;
      else //if not 7 than lose
	cout<<"=====Win====="<<endl;
    }
  
  return 0;
}
