//INSTRUCTION: FALL21
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors
// NEVER delete my comments!!!
//=========================================================
//HW#: HW1P2 queue
//Your name: Reinier Swanepoel
//Complier:  g++ compiler
//File type: queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{  // initialize data members as in the notes 
  front = 0; //initializing the queue should be 0 at start
  count = 0; //count should be 0 since we are just starting
  rear = -1; //rear is behind the initial starting position
}

//destructor 
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false - checks count
bool queue::isEmpty()
{
  if (front == 0 && rear == -1) // Rear should only be -1 if the array is empty. Front can be 0 but still have something in it, therefore we have 
    // a biconditional check
    {
      return true;
    }
  else//count is more than 0
    {
      return false;
    }
}

// PURPOSE: returns true if queue is full, otherwise false - checks count
bool queue::isFull()
{
  // Self explanatory - if the count of the array exceeds MAX_SIZE, the array is full.
  if (count == (MAX_SIZE-1))
    {
      return true;
    }
  else
    {
      return false;
    }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if (isFull()) // If it is full, we want to throw an exception called overFlow
    {
      throw overFlow(); //would be repititive to check count = max size
    }
  
  else
    {
      rear = (rear + 1) % MAX_SIZE; // Why this formula? Well, we want the rear to increase.
      
      // However, in the event that the queue becomes full, the rear should be reset.
      //   Thus, the queue, in a way is circular (where the front and the tail meet).
      //   So, for example, if the MAX_SIZE is 9...and the previous rear value was 8
      //   Plugging into the formula: (8 + 1) % MAX_SIZE would get us 0. 
      el[rear] = newElem;
      count++;
    }
    
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  
  // If the queue is empty, we will throw underFlow. After all, we do not want to attempt deleting from an empty queue.
  if (isEmpty())
    {
      throw underFlow();
    }
  
  else
    {
      // removedElem will serve as a holder for the element removed.
      removedElem = el[front];
      // We want to clear the original position by representing it with empty quotes, else the already deleted character will hang around in the buffer
      el[front] = " "; //empty the front and delete heap memory
      // Why this algorithm, you ask?
      //It is the same concept as moving the rear in the add function. We want to move the front up, thereby
      //   "erasing" the content of what is currently the front of the line. We include % MAX_SIZE because
      //   a queue based array is circular (the end will meet the beginning), so front will only be 0 when front + 1 == //MAX_SIZE.
      
      front = ((front + 1) % MAX_SIZE);
      count--;
    }

}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if (isEmpty())
    {
      throw underFlow();
    }
  else
    {
      // Notice that since the function is void, we cannot return a data type. Therefore, we can return data
      // by using a pass-by-reference. Remember, that pass-by-reference can return data because whatever is changed
      // on the pass-by-reference, will also reflect in the variable that is used in the main program function call.
      theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  // Notice that in this function, we want to return the CURRENT size of the queue, not the MAXIMUM SIZE
  // Remember that we have been incrementing and decrementing an integer variable called count in the add
  // and remove functions. So, since this function is int data return type, all we need to do is return count.
  // This will work because count is also an integer based variable.
  
  return count;// each slot of the array starts at 0 but has count elements
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  if (isEmpty()) 
    {
      cout << "[ empty ]" << endl;
    }
  else
    {
      int j = front;
      int current;
      cout << "[";
      for (int i = 1; i <= count; i++)
	{
	  current = j % MAX_SIZE;
	  cout << el[current];
	  j++;
	}
      cout << "]" << endl;   
    } 
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{ //  need a local variable
  //  remove and add
  // If the queue is empty, throw underFlow exception.
  if (isEmpty())
    {
      throw underFlow();
    }
  
  // No need to go to the back if the front and the rear are the same.
  else if (count > 1)
    {
      el_t element;
      remove(element);
      add(element);
    }
}


