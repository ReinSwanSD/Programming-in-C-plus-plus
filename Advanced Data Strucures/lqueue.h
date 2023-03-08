/******************************************************                                                                 Reinier Swanepoel                                                                                                                                                                       
lqueue.h
CS211                                                                                                                                                                                   
Kazumi Slott                                                                                                                                                                            
Linked Queue Class                                                                                                      header file, define the class and data members                                                                                                                         
*********************************************************/

#ifndef LQUEUE_H
#define LQUEUE_H

#include <string>

using namespace std;

typedef int el_t;

struct node
{                   // stuct that holds the element and a pointer to the next element
  el_t elem;
  node* next;
};

class LQueue
{

 private:
  node* front;                // address to the front element
  node* rear;                 // address to the last element
  int count;                  // how many elements do we have right now?
  void queueError(string msg);    // This displays an error messages passed to it and does exit(1);
  void printAllReverse(node* p); // shows all elements in reverse order
 
 public:
  LQueue();                   // constructor LQueue();
  ~LQueue();                  // deconstructor LQueue();
  
  //HOW TO CALL:  Call onto an existing LQueue ([LQueue].addRear(elem))
  //              with the element you want to add to the LQueue
  //PURPOSE:      to add a pointer with an element to te list
  void addRear(el_t elem);
    
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

  //HOW TO CALL:  Call onto an existing queue ([LQueeuName].printAllReverse())                                            //PURPOSE:      Reverse the elements in the linked queue  
  void printAllReverse();
    
};

#endif /* LQUEUE_H */

