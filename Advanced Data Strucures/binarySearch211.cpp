/***************************************************************************
Reinier Swanepoel
CS211
Binary Search Tree

Template created by Kazumi Slott
Implement binary search that works on an ascending and descending ordered list.
Your program will abort if the function doesn't return the correct value. 

Your name: Reinier Swanepoel
*****************************************************************************/
#include <iostream>
#include <assert.h> //include this for assert. This is coming from the C library, so you need .h 

using namespace std;

void reverseArray(int a[], int s);
int binarySearchAscend(const int a[], int s, int key);
int binarySearchDescend(const int a[], int s, int key);

int main()
{
  const int SIZE = 10;
  int ar[SIZE] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90};
  
  //test binarySearchAscend()
  for(int i = 0; i < SIZE; i++)
    assert(binarySearchAscend(ar, SIZE, ar[i]) != -1);  //assert() terminates if false
  assert(binarySearchAscend(ar, SIZE, 2) == -1); 
  
  //call reverseArray() to reverse the elements in ar 
  reverseArray(ar, SIZE);
  for(int i = 0; i < SIZE; i++){
    cout << ar[i] << " ";
  }
  cout << endl;
  
  
  //test binarySearrchDescend() - mimic how you tested binarySearchAscend()
  for(int i = 0; i < SIZE; i++)
    assert(binarySearchDescend(ar, SIZE, ar[i]) != -1);  //assert() terminates if false
  assert(binarySearchDescend(ar, SIZE, 2000) == -1);  
  
  return 0;
}



/****************************************************************************
This functioon reverse the contents of the array. Don't make a second array.
e.g. If ar is [5, 1, 3, 8, 2], this function changes the array to [2, 8, 3, 1, 5]
a is an integer array of any size.
s is the size of the array.
****************************************************************************/
void reverseArray(int a[], int s)
{

  int temp;
  int i = 0;
  int j = s-1;
 
  while (i < j)
    {
      temp = a[j];
      a[j] = a[i];
      a[i] = temp;
      i++;
      j--;
    }
  
}


/****************************************************************************
This function returns the index where key is found or -1 if key is not found.
a is an integer array of any size sorted in ascending order.
s is the size of the array.
key is the number being searched for.
****************************************************************************/
int binarySearchAscend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index
  int r = s-1; //right boundary starts at last index
  int m; //middle point between left and right.

  //When l and r cross over, search ends. --> key was not found. 
  while(r >= l)
    {
      //calculate the middle point between l and r
      m = (l+r)/2;
      if(a[m] == key) //key was found
	return m;
      else if(key < a[m])
	{
	  r = m - 1;
	}
      else if(key > a[m])
	{
	  l = m + 1;
	}
    }
  
  return -1; //key wasn't found
}

/****************************************************************************                                                             
This function returns the index where key is found or -1 if key is not found.                                                             
a is an integer array of any size sorted in descending order.                                                                                                     
s is the size of the array.                                                                                                               
key is the number being searched for.                                                                                                     
****************************************************************************/
int binarySearchDescend(const int a[], int s, int key)
{
 
  int l = 0; //left boudary starts at first index
  int r = s-1; //right boundary starts at last index
  int m; //middle point between left and right.
 
  //When l and r cross over, search ends. --> key was not found. 
  while(r >= l)
    {
      //calculate the middle point between l and r
      m = (l+r)/2;
      if(a[m] == key) //key was found
	return m;
      else if(key > a[m])
	{
	  r = m - 1;
	}
      else if(key < a[m])
	{
	  l = m + 1;
	}
    }
  
  return -1; //key wasn't found           
}
