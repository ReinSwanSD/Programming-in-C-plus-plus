/******

Reinier Swanepoel
3/28/2020
Chips and Salsa

Write a program that lets a maker of chips and salsa keep track of sales for five different types of salsa:
mild, medium, sweet, hot, and zesty. The program should use two parallel 5- element arrays: an array of
strings that holds the five salsa names and an array of integers that holds the number of jars sold during the
past month for each salsa type. The salsa names should be stored using an initialization list (using {}) at the
time the name array is created. The program should prompt the user to enter the number of jars sold for
each type. Once this sales data has been entered, the program should produce a report that displays sales for
each salsa type, total sales, and the names of the highest selling and lowest selling products. 


******/

//Header
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include"input.h"  //include input.h
using namespace std;
//prototypes
void fillJarsSoldArray(string names[],int jars[],int SIZE);
void printSales(string names[],int jars[],int SIZE);
int getTotal(int jars[],int SIZE);
int getHighestLowestSelling(int jars[],int SIZE);
int main() 
{
  //Declaring variables
  const int SIZE=5;
  string names[]={"mild","medium","sweet","hot","zesty"};
  int jars[SIZE];
  int total;
  int index[SIZE] = jars[SIZE];
  fillJarsSoldArray(names,jars,SIZE);
  printSales(names,jars,SIZE);
  total=getTotal(jars,SIZE);
  cout<<"\nThe total number of jars sold is "<<total<<endl;
  index=getHighestLowestSelling(jars,SIZE);
  cout<<"The highest selling type is "<<names[index[1]]<<endl;
  cout<<"The lowest selling type is "<<names[index[0]]<<endl;
  
  return 0;
}
void fillJarsSoldArray(string names[],int jars[],int SIZE)
{
  for(int i=0;i<SIZE;i++)
    {
      cout<<"Enter the number of jars sold for "<<names[i]<<":";
      jars[i]=getInt(0,1000000, "\t Invalid. The number of jars sold must be between 1 and 1000000");
      
    }
  
}
void printSales(string names[],int jars[],int SIZE)
{
  for(int i=0;i<SIZE;i++)
    {
      cout<<names[i]<<"\t"<<jars[i]<<endl;
    }
}
int getTotal(int jars[],int SIZE)
{
  int tot=0;
  for(int i=0;i<SIZE;i++)
    {
      tot+=jars[i];
    }
  return tot;
}
int getHighestLowestSelling(int jars[],int SIZE)
{
  int min=jars[0];
  int max=jars[0];
  int minIndx=0;
  int maxIndx=0;
  
  for(int i=0;i<SIZE;i++)
    {
      if(max<jars[i])
	{
	  max=jars[i];
	  maxIndx=i;  
	}
      
      if(min>jars[i])
	{
	  min=jars[i];
	  minIndx=i;  
	}
      
    }
     
  return;
}
