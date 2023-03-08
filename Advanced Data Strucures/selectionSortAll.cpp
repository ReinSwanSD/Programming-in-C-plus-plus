/****************************************************
Reinier Swanepoel
SelectionSortAll
Template written by Kazumi Slott
CS211
selection sort lab

This program has 4 different selection sort functions.
*****************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;
#include "array.h" // include your array.h
//proto types
void  fill(int array[], int N);
void test(int code);
void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);

int main()
{
  // srand(time(0));
  
  cout << "\n------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1);

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  test(2);

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  test(3);

  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  test(4);

  return 0;
}

//This function fills the array with random numbers between 1 and 100
// array=is the integer array , N=slots of array

void  fill(int array[], int N)
{
  srand(time(0));

  for (int i=0; i<N; i++)
    {
      array[i]= rand()%100+1;//num get some random dumber between 1 & 100
    }

}


//code = 1 for selectionSort1
//       2 for selectionSort2
//       3 for selectionSort3
//       4 for selectionSort4

void test(int code) //test codes 1-4
{
  //make a constant SIZE set to 10
  const int SIZE=10; 
  //declare an integer array using SIZE  
  int arrayA[SIZE];
  //fill the array by calling fill()
  fill(arrayA,SIZE);
  //print the array by calling print() in array.h
  int ans;
  cout<<endl;
  printArray(arrayA,SIZE);

  //create a switch statement here to call a different sort function depending on the code.
  cout<<"\n=============="<< endl; //setw(14)                                                                                                                                                   
  cout<<"1:selectionSort1 2:selectionSort2 3:selectionSort3 4:selectionSort4"<<endl;
  cout<<"=============="<< endl; 
      
  //enter choice
  cout<<"\nEnter your choice: ";
  cin>>ans;
  cout<<endl;  
  switch (ans) //switch will give user the choice to run thru all 4
    {
    case 1:
      {
	//	cout<<"Here are 10 random numbers generated from smallest to largest"<<endl;
	selectionSort1(arrayA,SIZE);
      }
      break;
    case 2:
      {
	//	cout<<"Here are 10 random numbers generated from largest to smallest"<<endl;
	selectionSort2(arrayA,SIZE);
      }
      break;
    case 3:selectionSort3(arrayA,SIZE);
      //      cout<<"Here are 10 random numbers generated from smallest to largest"<<endl;                             

      break;
    case 4:selectionSort4(arrayA,SIZE);
      //      cout<<"Here are 10 random numbers generated from largest to smallest"<<endl;                             

      break;
    }
  
  
  
  
//print the array - hopefully the numbers are sorted correctly

  printArray(arrayA,SIZE);
  cout<<endl<<endl;

}



//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N) 
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--) 
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] > array[lrgIndx]) //The current item is larger 
	    lrgIndx = i;
	}

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx]; 
      array[lrgIndx] = array[last]; 
      array[last] = temp;
    } 
}



//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int smlIndx; //the index of the smallest value                                                                                                                                               
  int temp; //temp variable that holds the smallest value

  //last is the last index in unsorted part                                                                                                                                                
  for(int last = N-1; last >= 1; last--)
    {
      smlIndx = 0; //assume the first number in array is smallest
                                                                                                                                      
      //find the smallest and move it to last                                                                                                                                      
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[smlIndx]) //if smaller move it to last index                                                                                                                          
            smlIndx = i;
        }

      //swap the smallest with the last item in the unsorted part                                                                                                                           
      temp = array[smlIndx];
      array[smlIndx] = array[last];
      array[last] = temp;
    }
}


//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int smlIndx; //the index of the smallest value                                                                                                                                                                        
  int temp; //variable that holds the smallest value                                                                                                                                                                           
  //first is the first index in the unsorted part
  for(int first = 0; first < N-1; first++)
    {
      smlIndx = first; //assume the first number in the array is the smallest                                                                                                                                                                   
      for(int i =first+1; i < N; i++)
        {
          if(array[i] < array[smlIndx]) //if smaller move to small index                                                                                                                                            
            smlIndx = i;
        }
      
      //swap the smallest with the first index of the unsorted part
      temp = array[smlIndx];
      array[smlIndx] = array[first];
      array[first] = temp;
    }
}



//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort4(int array[], int N)
{
  int lrgIndx; //the index of the smallest value
  int temp; //variable that holds the smallest value

  //first is the first index of the array                                                                                                                                                                                                                                                                                                                                    
  for(int first = 0; first < N-1; first++)
    {
      lrgIndx = first; //assume the first number in the array is the largest \
      
      //find the largest and move it to the beginning				\
      
      for(int i =first+1; i < N; i++)
        {
          if(array[i] > array[lrgIndx]) //if larger move to the first index of the unsorted part \
	    
            lrgIndx = i;
        }
      
      //swap the largest with the first index of the unsorted part     
      
      temp = array[lrgIndx];
      array[lrgIndx] = array[first];
      array[first] = temp;                                                                                                                                              
      
    }
}










