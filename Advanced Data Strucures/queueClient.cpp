/*********************************************************
Template provided by Kazumi Slott

Name: Reinier Swanepoel
This client tests the queue class memeber functions.
********************************************************/
#include <iostream>
#include "queue.h"
#include "checkInput.h"

using namespace std;

//prototypes
void addElem(Queue&);
void remElem(Queue&);
void frontElem(Queue&);
void goBack(Queue&);
void getElems(Queue&);
void display(Queue&);
void showMenu(Queue&);

int main()
{
  Queue que; //make a queue
  
  showMenu(que); //menu options
  
  return 0;
}


void showMenu(Queue&q)
{
  int choice;
  
  do{
    
    cout << "1: add a new element" << endl; //(testing add(), isFull())
    cout << "2: remove an element" << endl; // (testing remove(), isEmpty())
    cout << "3: check the front element" << endl; //(testing getFront(), isEmpty())
    cout << "4: go back to the rear" << endl; //(testing goToBack())
    cout << "5: get the number of elements in the queue" << endl; //(testing getSize()) 
    cout << "6: display all the elements in the queue" << endl; //(testing displayAll()) 
    cout << "7: quit program" << endl;
    cout << "Menu choice: ";
    
    //choice needs to be between 1 and 7, using inputcheck.h
    choice = getData(1, 7, "Invalid choice.\nMenu Choice: ");
    
    //once we get a choice, go to one of the following functions
    switch (choice)
      {
      case 1 :addElem(q);
	break;
      case 2 : remElem(q);
	break;
      case 3 : frontElem(q);
	break;
      case 4 :goBack(q);
	break;
      case 5 : getElems(q);
	break;
      case 6 : display(q);
	break;
      }
    //7 is our exit function, so we'll wanna exit the loop to exit the program
  } while (choice != 7);
}


//afunction to add an element to the queue
void addElem(Queue& q) 
{
  char ch;
  if (!q.isFull()) 
    {      //make sure the queue isn't full
      cout << "\nEnter a character to add to the queue: ";        //ask user for a letter
      //using inoutcheck, we can insure it is a letter and give an error msg if necessary
      ch = getData('A','Z',"Character is invalid. Must be an alphabetic character.\nEnter a character to add to the queue: ");
      q.add(ch);      //add the character to the queue
      cout << endl;
    }
  else// if(q.isFull())
    {      //else, the queue must be full and we leave the function
      cout << "\nQueue is full. Unable to add another element.\n" << endl;
    }
}
void remElem(Queue& q)
{
  if (!q.isEmpty())
    {     //make sure the queue isn't empty
          //remove the front element
      cout << "\nElement "<<q.remove()<<" removed.\n" << endl;     //let the user know that the operation is complete
    }
  else 
    {      //else the queue must be empty and we leave the function
      cout << "\nQueue is empty. Unable to remove an element.\n" << endl;
    }
}

//a function to get the front element of the queue
void frontElem(Queue& q)
{
  if (!q.isEmpty())
    {     //make sure the queue isn't empty
      //display the front element
      cout << "\nThe front element is: " << q.getFront() << endl << endl;
    }
  else
    {      //else, the queue must be empty and we leave the function
      cout << "\nQueue is empty. There is no front element.\n" << endl;
    }
}

//a function to move the front element to the back of the queue
void goBack(Queue& q)
{
  if (!q.isEmpty())
    {     //check if the queue is empty
      q.goToBack();       //move the front element to the back
      cout<<endl;
    }
  else
    {      //else the queue must be empty and we leave the function
      cout << "\nQueue is empty. Cannot to the rear element.\n" << endl;
    }  
}

//function to get the size of the queue
void getElems(Queue& q)
{
  //display the number of elements
  cout << "\nThe number of elements in the queue is: " << q.getSize() << endl << endl;
}

//a function to display all the elements in the queue
void display(Queue& q) 
{
  if (!q.isEmpty()) 
    {     //check if the queue is empty
      q.displayAll();     //display the queue
    }
  else
    {      //else, the queue must be empty, and we leave the function
      cout << "\nQueue is empty. No elements to display.\n" << endl;
    }
}
