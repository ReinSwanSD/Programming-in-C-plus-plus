/*******************

Reinier Swanepoel
3/25/2020

Array.cpp

one at a time:
You are going to make a program with an array of integer values. You will create 3 operations on
the array for this lab (and add several more functions for assignment 6) and call each operation from a switch
using a do-while loop.

*******/
#include<cstdlib> //for random number generator
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include <iostream>
using namespace std;

//prototypes
void fillArray(int ar[], int size);
void printArray(const int ar[], int size);
double findAvg(const int ar[], int size);
int find(const int ar[], int size,int key);

void selectionSortAscend(int ar[],int size);
void selectionSortDescend(int ar[], int size);

void reverseArray(int ar[], int size);
int findHighest(int ar[],int size);
void doubleArray(int ar[], int size);
d showBarGraph(int ar[],int size);
int binarySearchAscending(const int ar[], int size, int key);
int binarySearchDescending(const int ar[], int size, int key);

//main

int main()
{//variables
  const int SIZE=5; //not changing/constant
  int ar[SIZE]; //array as big as size
  double average; //average is total divide by size
  int ans; //choice menu response
  int key; //number your looking for
  int location;
  // int lrgIndx; //the index of the largest value
  // int temp; //temporary variable that holds the largest value

  //  bool found; //true or false if found
  do
    {
      //menu options
      cout<<"\n=============="<< endl; //setw(14)
      cout<<"1:fill the array 2:print the array 3:reverse the array 4:show the average 5:find highest in array 6:double each number in array 7:display bar graph 8:selection sort ascending 9:selection sort descending 10:sequential search 11:binary search ascending 12:binary search descending 13:quit"<<endl;
      cout<<"=============="<< endl;
      //enter choice
      cout<<"Enter your choice: ";
      cin>>ans;
      cout<<endl;
      //switch menu options
      switch(ans)
	{
	case 1:fillArray(ar, SIZE);
	  break;
	case 2:printArray(ar, SIZE);
	  break;
	case 3:reverseArray(ar,SIZE);
	  break;
	case 4:average= findAvg(ar, SIZE);
	  cout<<"The average is "<<average<<endl;
	  break;
	case 5:
	  location=findHighest(ar,SIZE);
	  cout<<"The highest number is "<<ar[location]<< " found at index "<<location<<endl;
	  break;
	case 6: doubleArray(ar,SIZE);
	  break;
	case 7: showBarGraph(ar,SIZE);
	  break;
	case 8:selectionSortAscend(ar,SIZE);
	  break;  
	case 9:selectionSortDescend(ar,SIZE);
	  break;
	case 10: //sequential search ???
	  {
	    cout<<"Enter the key: ";
	    cin>> key; //is the number u want to find in array
	    cout<<endl;
	    location = find(ar,SIZE,key);	    
	    if(location != -1) //many ways
	      {
		cout<< key << " was found in the index "<<location<<endl;
	      }
	    else
	      {
		cout<< key << " was not found in the index."<<endl;
	      }
	  }
	  break;
	case 11: //binary search ascending ????
          {
            cout<<"Enter the key: ";
            cin >> key; //is the number u want to find in array
            cout<<endl;
	    location = binarySearchAscending(ar,SIZE,key);
	    if(location != -1) //many ways
	      cout<< key << " was found in the index "<<location<<endl;
	    else
	      cout<< key << " was not found in the index."<<endl;
	  }
	  break;
	case 12: //binary search descending ???
	  {
            cout<<"Enter the key: ";
            cin>> key; //is the number u want to find in array
            cout<<endl;
            location=binarySearchDescending(ar,SIZE,key);
            if(location != -1) //many ways
              {
                cout<< key << " was found in the index "<<location<<endl;
              }
            else
              {
                cout<< key << " was not found in the index."<<endl;
              }
          }
	  break;
	case 13:cout<<"Thank you for using our system."<<endl; //only cancel for 
	  break;
	  // default:cout<<"Thank you for using our system.";
	}
    }while(ans!=13); //only 13 to exit
  
  //fillArray(ar, SIZE);
  //printArray(ar, SIZE);
  //average= findAvg(ar, SIZE);
  //cout<< "The average is " <<average<<endl;

  return 0;
}
/****
This function will fill the array and share the parameter of size
****/
void fillArray( int ar[], int size)
{
  //  srand(time(0)); //as stated in directions
  //  cout<<"Your random numbers are being generated...please wait "<<endl;

  for(int i=0; i<size; i++)
    {
            cout<<"Enter a number: ";
	    // ar[i]=rand()%50+1;
      	    cin >> ar[i];
            cout<<endl;
    }

}
/*******
this function will print all the array items and keep them the same
*******/
void printArray(const int ar[], int size)
{
  cout << "The numbers in the array are ";
  
  for(int i=0; i<size; i++)
    {
      cout <<ar[i]<<" ";
    }
  cout<<endl;
}
/******
this function will find the average, declare total variable and add up
******/
double findAvg(const int ar[], int size)
{
  int total=0;
  for (int i=0; i< size; i++)
    {
      total+= ar[i];
    }
  cout << fixed << setprecision(2);
  return (double)total/size;
}

/******
This function will search the index and find if they key was in the array or not in the array
ar is array , size is 5, key is entered by user
*******/

int find(const int ar[], int size,int key)
{
  for(int i= 0; i<size; i++)
    {//check all index
      if(ar[i]==key)
	{
	  //cout<< key << " was found in the index "<<i<<endl;
	  return i;
	}
      
    }
  //cout<< key << " was not found in the index."<<endl;
  return -1;
}

/*****
//this function will sort the numbers in ascending order: smallest up to largest

****/
void selectionSortAscend(int ar[],int size)
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted portion
  for(int last = size-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted portion ([0..last])
      for(int i = 1; i <= last; i++)
        {
          if(ar[i] > ar[lrgIndx]) //The current item is larger
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion
      temp = ar[lrgIndx];
      ar[lrgIndx] = ar[last];
      ar[last] = temp;
    }
}


/********
//this function will sort the numbers in descending order: smallest up to largest

*******/
void selectionSortDescend(int ar[], int size)
{
  int lrgIndx; //the index of the smallest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted portion
  for(int last = size-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted portion ([0..last])
      for(int i = 1; i <= last; i++)
        {
          if(ar[i] < ar[lrgIndx]) //The current item is larger
            lrgIndx = i;
        }

      //swap the smallest with the last item in the unsorted portion
      temp = ar[lrgIndx];
      ar[lrgIndx] = ar[last];
      ar[last] = temp;
    }
}

/*********

This function will reverse the order of the array
using two indices (left and right)

*******/

void reverseArray(int ar[], int size)
{
  cout<<"Your array is being reversed...please wait"<<endl;
  int left=0;
  int right= size -1;
  int temp;

  for(left=0,right=size-1;left<right;left++, right--)
    {
      temp=ar[left];
      ar[left]=ar[right];
      ar[right]=temp;
    }
}

/******

this funvtion will findHighest: Returns the index of the highest number. Do not show the highest number along
with the location in findHighest() instead show them in the main.

******/

int findHighest(int ar[],int size)
{
  int highestIndex=0;

  for(int i=1; i<size; i++)
    {
      if(ar[i]>ar[highestIndex])
	{
	  highestIndex=i;
	}
      return i;
    }

}
/********

This function will double all the values in the array,
physically change each number

*******/

void doubleArray(int ar[], int size)
{
  cout<<"Your array is being doubled...please wait"<<endl;
  for (int i=0; i<size; i++)
    {
      ar[i]=ar[i] * 2;

    }
}
 

/*******

this function will display a bar graph 
a row of asteriks for each slots

*******/

void showBarGraph(int ar[],int size)
{
  
  for(int i=0;i<size;i++)
    {
      cout<<"Slot "<<i<<":";
      for(int j=0;j<ar[i]/10;j++)
	{
	  cout<<"*";
	}
      cout<<endl;
    }
}


/******

This function will binary search the ascending array

******/
int binarySearchAscending(const int ar[], int size, int key)
{
  int l = 0; //left boudary starts at first index
  int r = size - 1; //right boundary starts at last index
  int m; //middle point between left and right boundaries.

  //as long as l and r are not crossed over.
  //When l and r cross over, search ends. --> key was not found.
  while( l <= r )
    {
      //calculate the middle point between l and r
      m = (l + r)/2;

      if(ar[m] == key)
        return m;
      else if(key < ar[m])
        r = m - 1;
      else //if(ar[m] < key)
        l = m + 1;
    }

  return -1; //key wasn't found
}

/******

This function will binary search the ascending array

******/

int binarySearchDescending(const int ar[], int size, int key)
{
  int l = 0; //left boudary starts at first index
  int r = size - 1; //right boundary starts at last index
  int m; //middle point between left and right boundaries.

  //as long as l and r are not crossed over.
  //When l and r cross over, search ends. --> key was not found.
  while( l <= r )
    {
      //calculate the middle point between l and r
      m = (l + r)/2;

      if(ar[m] == key)
        return m;
      else if(key > ar[m])
        r = m - 1;
      else //if(ar[m] < key)
        l = m + 1;
    }

  return -1; //key wasn't found
}

