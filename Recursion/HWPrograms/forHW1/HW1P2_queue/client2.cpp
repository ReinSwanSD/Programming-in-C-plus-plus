//CS311 Yoshii FALL21
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
// NEVER delete my comments!!!!
//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Reinier Swanepoel
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"


//Purpose of the program:
// This program will utilize a queue to display every possible combination of using the strings A, B, C.

//Algorithm: We will first want to create an object of queue. Then we want to call the add function (for concatenation) and the display function (to display the results)
// This should be done in a never ending loop  that has a condition that if the while loop is not empty, then it removes the first element
// of the queue and adds it to the string A, B, and C. The added string then gets added to the queue and the new list of elements get displayed.

int main()
{ // A, B, C in the queue
    
  queue myQueue; // object of queue class (data structure)
    
  string ele1 = "A"; // Creates a memory location called A, that is of data type string, and stores the letter A into it.
  string ele2 = "B"; // Creates a memory location called B, that is of data type string, and stores the letter B into it.
  string ele3 = "C"; // Creates a memory location called C, that is of data type string, and stores the letter C into it.
     
  myQueue.add(ele1); // This will add A to the queue.
  myQueue.add(ele2); // This will add B to the queue.
  myQueue.add(ele3); // This will add C to the queue.
  
  /* cout << "[ "; double check it was added
  myQueue.displayAll();
  cout << " ]" << endl;
  */
  while (!myQueue.isEmpty())
    {
        try
	  {
	    myQueue.remove(ele1);
            cout << ele1 << endl;
            myQueue.add(ele1 + "A"); // Concatenation
            myQueue.add(ele1 + "B"); // Concatenation
            myQueue.add(ele1 + "C"); // Concatenation
            
	    // cout << endl;
            // double check but not needed for output
	    // cout << "COUNT: " << myQueue.getSize() << endl;
	    // myQueue.displayAll();
	  } // end of try
        
        catch (queue::overFlow)
	  {
            cerr << "ERROR: CANNOT ADD! THE QUEUE IS FULL!" << endl;
	    //system("PAUSE"); from cs211 if you want the system to pause
            exit(1);
	  } // end of catch overFlow
        catch(queue::underFlow)
	  {
            cerr << "ERROR: THE QUEUE IS EMPTY!" << endl;
	    //system("PAUSE");
            exit(1);
	  } // end of catch underFlow
    } // end of while
    
  cout << endl;
    
  return 0;
}
