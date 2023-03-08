/*******************************************************                                                                Reinier Swanepoel                                                                  Reinier Swanepoel                                                                                                     
LL.h
CS211                                                                                                                                                                                   
Kazumi Slott                                                                                                                                                                            
Linked List Class                                                                                                                  
header file, define the class and data members                                                                          

*********************************************************/

#ifndef LL_H
#define LL_H

#include <string>
#include <iostream>

using namespace std;

typedef int el_t;

struct node
{                   // stuct that holds the element and a pointer to the next element
  el_t elem;
  node* next;
};

class LL
{

 private:
  node* front;                // address to the front element
  node* rear;                 // address to the last element
  int count;                  // how many elements do we have right now?
  void queueError(string msg);    // This displays an error messages passed to it and does exit(1);
  void printAllReverse(node* p); //recursion for print all reverse function, reverses the elements
 
 public:
  LL();                   // constructor LL();
  ~LL();                  // deconstructor LL();
  LL(const LL& l);        // copy construction
    
  //HOW TO CALL:  Call onto an existing LQueue ([LQueue].addRear(elem))
  //              with the element you want to add to the LQueue
  //PURPOSE:      to add a pointer with an element to te list
  void addRear(el_t el);
    
  //HOW TO CALL:  Call onto an existing LQueue ([LQeueue.deleteFront())
  //PURPOSE:      Deletes the rear pointer and returns the element
  el_t deleteFront();
    
   //HOW TO CALL:  Call onto an existing queue ([LQueueName].isEmpty())
  //PURPOSE:      Checks if the queue has no (0) elements and returns
  //              true or false accordingly
  bool isEmpty();
    
  //HOW TO CALL:  Call onto an existing queue ([LQueeuName].displayAll())
  //PURPOSE:      Displays all elements in the LQueue
  void displayAll();
    
  //HOW TO CALL:  Call onto an existing queue with the element you want
  //              to add as a parameter ([LLName].addFront(elem))
  //PURPOSE:      To add an element to the front of the LL
  void addFront(el_t el);

  //HOW TO CALL:  Call onto an existing LL ([LL.deleteRear())
  //PURPOSE:      Deletes the front pointer and returns the element
  el_t deleteRear();

  //HWO TO CALL:  Call on existing lqueue ([lqueueName].displayAll())
  //PURPOSE:      To print all the elements in reverse. Calls
  //              printAllReverse(node<T>*) to reverse recusively
  void printAllReverse();

  //HOW TO CALL:  Call onto an existing LL ([LL.deleteRear())                                                                                                                                              
  //PURPOSE:      Deletes the front pointer and returns the element  
  void deleteNode(el_t e);

  //HOW TO CALL:  Call onto an existing LL ([LL.deleteRear())                                                                                                                                              
  //PURPOSE:      Deletes the front pointer and returns the element  
  void deleteNodes(el_t e);

  bool search(el_t e);

  void addInOrderAscend(el_t el);

};

#endif /* LL_H */

