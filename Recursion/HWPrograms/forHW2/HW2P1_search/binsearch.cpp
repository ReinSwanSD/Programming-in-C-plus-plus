using namespace std;
#include <iostream>
// CS311 YOSHII FALL21
// The Algorithm is in Notes-4A so copy and paste it here!!!!!
// On Empress, control-rightclick will bring up the paste option.
// NEVER delete my comments!!!
//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Reinier Swanepoel
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
// This recursive function returns the slot number in which x was found
// or -1
int binarySearch(int L[], int x, int first, int last) 
{
  //  Be sure to check for first > last and
  //   first == last cases to
  //   end the recursion 
  int middle = (first+last)/2;

  // as soon as the mid is found...                                                                                      
  cout << "comparing against an element in slot " << middle << endl;
    
  if (x == L[middle])     // Returns if x is in middle
    return middle;
  else if (first == last) // Returns -1 if not found with one slot
    return -1;
  else if (x < L[middle])
    last  = middle - 1; // Searches the first half
  else if (x > L[middle])
    first = middle + 1; // Searches the second half

  // The rest based on the notes
  return binarySearch(L, x, first, last); // Recursive Function
}


int main()
{ int A[10];
  int e;  // to look for this
  int first = 0; //need to intiate for function
  int last = 9; //need for function input

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;
  
  for (int i=0; i<10; i++)
    {
      cout << A[i] <<" ";
    }

  cout << "\nWhat do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A,e,first,last); //since recursive function has 4 elements, you need 4

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

  return 0;
}
