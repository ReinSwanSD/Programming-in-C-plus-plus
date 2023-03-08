/***************************************************************
Reinier Swanepoel
arrayTest.cpp
CS211
Template prepared by Kazumi Slott
1-28-2020

This program tests array.h
**************************************************************/

#include <iostream>
using namespace std;
#include "array.h"


int main()
{
  //declare const called SZ_I set to 7
  const int SZ_I = 7;

  //declare const called SZ_D set to 3
  const int SZ_D=3;

  //declare const called SZ_C set to 5
  const int SZ_C=5;

  //unique size

   //create an integer array that has SZ_I slots
  int arrayA[SZ_I];
  int uniqueA[SZ_I];
  //create a double array that has SZ_D slots
  double arrayB[SZ_D];
 
  //create a character array that has SZ_C slots
  char arrayC[SZ_C];
  char uniqueC[SZ_C];

  //call fill with the integer array
  cout<<"-----Filling the integer array-----"<<endl;
  fillArray(arrayA,SZ_I);
  //call fill with the double array
  cout<<"-----Filling the double array-----"<<endl;
  fillArray(arrayB,SZ_D);
  //call fill with the character array
  cout<<"-----Filling the character array-----"<<endl;
  fillArray(arrayC,SZ_C);

 
  //call print (with 2 parameters) with the integer array
  printArray(arrayA,SZ_I);
  cout<<endl;
  //call print with the double array
  printArray(arrayB,SZ_D);
  cout<<endl;
  //call print with the character array
  printArray(arrayC,SZ_C);
  cout<<endl;
  
  //call getHighest with the character array and show the highest value along with its location
  int highest = getHighest(arrayC,SZ_C);
  cout<<"The Highest is " <<arrayC[highest]<< " at "<< highest <<endl;
  
  //call getLowest with the duoble and show the lowest value along with its location
  int lowest =  getLowest(arrayB,SZ_D);
  cout<<"The Lowest is "<< arrayB[lowest]<<" at "<<lowest<<endl;
  
  //call getAvg with the integer array and show the returend value
  double average = getAvg(arrayA,SZ_I);
  cout<<"The Average is "<< average<<endl;

  //call unique with integer array and show unique array and the number of unique numbers

  int uniqueNum=unique(arrayA,uniqueA,SZ_I);
  printArray(uniqueA,uniqueNum);
  cout<<"\nThe total number of unique integers is "<<uniqueNum<<endl;////

  //call unique with character array and show unique array and the number of unique numbers
  uniqueNum=unique(arrayC,uniqueC,SZ_C);
  printArray(uniqueC,uniqueNum);
  cout<<"\nThe total number of unique characters is "<<uniqueNum<<endl;/////

  /**
  //sort the double array and print it
  sort(arrayB,SZ_D);
  printArray(arrayB,SZ_D);
  cout<<endl;
  //sort the character array and print it
  sort(arrayC,SZ_C);
  printArray(arrayC,SZ_C);
  cout<<endl;

  cout<<endl;
  cout<<"Bubble Sort"<<endl;
  //bubble sort the integer array
  bubbleSort(arrayA,SZ_I);
  printArray(arrayA,SZ_I);
  cout<<endl;

  //bubble sort the double array

  bubbleSort(arrayB,SZ_D);
  printArray(arrayB,SZ_D);
  cout<<endl;

  //bubble sort the character array
  bubbleSort(arrayC,SZ_C);
  printArray(arrayC,SZ_C);
  cout<<endl;
  
  //find function

  int found=find(arrayA,SZ_I,9);
  cout<<found<<endl;
   
  cout<<endl;                                                                                                    
  int found= remove(arrayA,SZ_I,9);
  printArray(arrayA,SZ_I);
  cout<<endl<<found<<endl;
  *****/
  return 0;
}

