/*****************************************************
Reinier Swanepoel
array.h

Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name: Reinier Swanepoel
*****************************************************/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
//       fill
template <class T>
void fillArray (T ar[], int n)
{ 
  for (int i=0; i<n; i++)
    {
      cout<<"Enter an item: ";
      cin>> ar[i];
    }         
}



/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
       //         print

template <class T>
void printArray (const T ar[], int n)
{
  for(int i=0; i<n; i++)
    cout<<ar[i]<<" ";
}


/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
       //       getHighest
template<class T>
int getHighest (const T ar[],int n)
{
  int highest=0;
  for (int i=1; i<n;i++)
    {
      if(ar[i]>ar[highest])
	{highest=i;}

    }

  return highest;

}

////////////////////////////highest                                                                                    

/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
       //       getLowest
template<class T>
int getLowest(const T ar[], int n)
{
  int lowest=0;
  for (int i=1; i<n;i++)
    {
      if (ar[i]<ar[lowest])
	{lowest=i;}
    }

  return lowest;
}



/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
       //       getAvg
template<class T>
double getAvg (const T ar[], int n)
{
  double average=0.00000000000;
  double total=0.0000000000000;
  int count=0;
  
  for (int i=0; i<n;i++)
    {
      total=ar[i]+total;
      count++;
    }
  average=(double)(total/(n));

  return average;
}


/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/

template <class T>
int unique(const T ar[],T uniqAr[] , int n)
{
  int count=0;//size in the unqiue array
  bool same; //if number was found in the reg array
  uniqAr[0]=ar[0]; //store the first number in the unique array since there are no numbers
  
  for(int i = 0; i<n; i++)
    {
      same=false;
      
      for(int j=0; j<count && same == false;j++)
	{
	  if(ar[i] == uniqAr[j])
	    {	    
	      same=true;
	    }	  
	}      
	  if(same==false) 
	    {     
	      uniqAr[count++]=ar[i];
	    }
            
    }	 
  return count;    
}

//uniqAr in the caller will be filled with only unique numbers

/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

template <class T>
void sort(T  ar[], int n) // void sort(t&array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                               
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = n-1; last >= 1; last--)
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


/****************************************

This function sorts the items in decending order : largest to smallest

Using bubble sort,

array is the array of any data type
N is the number of items in the array

****************************************/

template <class T>
void bubbleSort(T ar[], int n)
{

  T temp; // temp is used to hold the temporary value of array
  bool done= false; //use this in the while loop while the array isnt done
  int last; // index used for left elements in the last pair array to be checked
  while(!done) //if not sorted
    {
      done=true;
      last=n-2;
      
      for (int i=0; i<=last;i++) //from first to second to last in unsorted array
	{
	  if (ar[i]>ar[i+1]) //if smaller then swap
	    {
	      //swapping larger to the front of the array
	      temp=ar[i];
	      ar[i]=ar[i+1];
	      ar[i+1]= temp;
	      done=false;	     	     	      
	      //  n--;
	    }
	  
	}
      last--; // the area to be cheked shrink down after each iternation
    }

}

/********************************

This function will search the array and see if it exists

*******************************/

template <class T1, class T2>
int find( T1 ar[], int n, T2& k)
{

  for (int i=0; i<n;i++)
    {
      
      if(ar[i]== k)
	{
	  return i;
	}
      
    }  
  //  if(ar[i]!= k)
  
  return -1;
}



/******************************

This function will remove any matching elements in the array

will return true if it can remove, will return false if not

*******************************/

template <class T1,class T2>
bool remove(T1 ar[], int n,const T2& k)
{
  int found=find(ar,n,k);
  if (found != -1)
    {
      for (int i =found; i<n-1;i++)
	{
	  //if ( ar[i]==k)
	  //  {
	      // for(int j=i; j<n;j++)
	      //	{
		  ar[i]=ar[i+1];
	      //	}
	      //	      n--; test output
		  //  }
	}     
      //      printArray(ar,n);

      return true;
    }
  else
    {
      return false;
    }
}
#endif
