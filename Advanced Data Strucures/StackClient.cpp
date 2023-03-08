/**************

Reinier Swanepoel

CS211 Stack Client
Stack CLient - Implementation File

****************/

#include <iostream>
#include "stack.h"

void addPerson(Stack&mySt,string name);

int main()
{
  Stack myStack;
  if (myStack.isEmpty())
    {
      cout << "The stack is empty" << endl << endl;
    }
    
  //  myStack.push("Mike");
  addPerson(myStack,"Mike");
  //  myStack.push("Kathy");
  addPerson(myStack,"Kathy");
  
  cout << myStack.topElem() << " is at the top." << endl;
    
  //myStack.push("Dave");
  addPerson(myStack,"Dave");
  //myStack.push("Alice");
  addPerson(myStack,"Alice");
  //myStack.push("Tom");
  addPerson(myStack,"Tom");

  if (myStack.isFull())
    {
      cout << "\nThe stack is full" << endl << endl;
    }
    
  myStack.displayAll();
 
  addPerson(myStack,"Meg");
  /*   
  if (myStack.isFull())
    cout << "\nYou cannot push. The stack is full" << endl << endl;
  else
    myStack.push("Meg");
  */  
  myStack.pop();
    
  cout << myStack.topElem() << " is at the top." << endl << endl;
    
  myStack.clearIt();
    
  if (myStack.isEmpty())
    {
      cout << "The stack is empty" << endl;
    }
    
    
  return 0;
}

void addPerson(Stack&mySt, string name)
{
  if(!mySt.isFull())
    mySt.push(name);
  else
    cout<<"\nYou cannot push. The stack is full." << endl << endl;

}
