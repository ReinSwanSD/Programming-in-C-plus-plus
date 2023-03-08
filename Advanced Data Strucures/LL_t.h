/*******************************************************                                                                                                 
Reinier Swanepoel
CS211
Kazumi Slott

LL_T.h

template for LL
header file, define the class and data members
*********************************************************/

#ifndef LL_T_h
#define LL_T_h

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

template <class T>
struct node
{
  T elem; 
  node<T>* next; 
};


//class LL_T

template <class T>
class LL
{

 private:
  node<T>* front;
  node<T>* rear;
  int count; 
  void LLError(string msg);
  void printAllReverse(node<T>* p);
 
 public:
  LL();
  ~LL();
  LL(const LL<T>& l);
  void addRear(const T& el);
  void addFront(const T& el);
  T deleteFront();
  T deleteRear();
  void deleteNode(const T& e);
  void deleteNodes(const T& e);
  bool isEmpty();
  void displayAll();
  void printAllReverse();
  bool search(const T& e);
  void addInOrderAscend(const T& el);
};


//queueError() 
//Print an error message (parameter) when called.

template <class T>
void LL<T>::LLError(string msg)
{
  cout << msg;
  exit(1);
}


//LL() Constructor

template <class T>
LL<T>::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}


//LL() Destructor
//Clears queue by repeatedly calling deleteFront().

template <class T>
LL<T>::~LL()
{
  while (isEmpty() == false)
    {
      deleteFront();
    }
}


//LL() Copy constructor
//Copies all elements to a new LL array.

template <class T>
LL<T>::LL(const LL<T>& l)
{
  front = rear = NULL; //both this front and this rear are null
  count = 0; //this count is 0
  node<T>* p; //new node
  p = l.front; //new node points to l.front
  while(p != NULL)
    { //loop until p is null
      this->addRear(p->elem); //adds p->elem to the front
      p = p->next; //advance p
    }
}


//addRear()
//Adds an element to the rear og the LL.

template <class T>
void LL<T>::addRear(const T& el)
{
  if (isEmpty() == true)
    { //first element in the queue
      front = new node<T>; //creates a new node for front
      rear = front; //because it is the first node, rear will = the front
      front->elem = el; //front elem is inserted
      rear->next = NULL;
    }
  else
    { //2+ elements
      rear->next = new node<T>; //new node
      rear = rear->next; //rear points to new node, since it will be at the rear
      rear->elem = el; //insert element
      rear->next = NULL;
    } 
  count++;
}


//addFront()
//Adds an element to the rear og the LL.

template <class T>
void LL<T>::addFront(const T& el)
{
  if (isEmpty() == true)
    { //first element in the queue
      front = new node<T>; //creates a new node for front
      rear = front; //because it is the first node, rear will = the front
      front->elem = el; //front elem is inserted
      rear->next = NULL;
    }
  else
    { //2+ elements
      node<T>* p;
      p = new node<T>;
      p->elem = el;
      p->next = front;
      front = p;
    } 
  count++;
}


//addInOrderAscend()
//Adds an element to the LL, but makes sure that it maintains numerical order when adding.

template <class T>
void LL<T>::addInOrderAscend(const T& el)
{
  if (count == 0)
    { //if empty and first element is needed
      front = new node<T>; //creates a new node for front
      rear = front; //because it is the first node, rear will = the front
      front->elem = el; //front elem is inserted
      rear->next = NULL;
      count++;
    }
  else if (el < front->elem)
    {//smallest elem
      node<T>* p;
      p = new node<T>; //new node to hold el
      p->elem = el;
      p->next = front; //after p is old front
      front = p; //p is new front
      count++; //incriment
    }
  else if (el > rear->elem)
    { //largest
      rear->next = new node<T>; //new node
      rear = rear->next; //rear points to new node, since it will be at the rear
      rear->elem = el; //insert element
      rear->next = NULL;
      count++; //incriment
    }
  else
    {
      node<T>* pre; //before insert
      node<T>* post; //after insert
      node<T>* e; //inserted node
      e = new node<T>; //e holds the new element
      e->elem = el;
      pre = front; //pre starts at front to locate insert position
      while (pre->next != NULL && pre->next->elem < el)
	{
	  pre = pre->next; //pre is advanced until position found
	}
    post = pre->next; //post is existing node after pre
    pre->next = e; //reorder pre->e->post
    e->next = post;
    count++; //incriment
    }
}


//deleteFront()
//Deletes front node. If the queue is empty, an error funtion is called.

template <class T>
T LL<T>::deleteFront()
{
  T old;
  if (isEmpty() == true) //if it is empty, cannot delete, error message
    LLError("The LL is empty. Cannot delete.");
  else if (count == 1)
    { //deleting the rear
      node<T>* p; //new pointer node
      p = front; //let p hold the element to be deleted
      old = front->elem; //will return old front element at the end
      rear = NULL; //rear and front need to be NULL
      front = NULL;
      count--; //incriment down 
      return old; //return it to main
    }
  else
    {
      node<T>* p; //new pointer node
      p = front->next; //set pointer to front
      old = front->elem; //will return old front element at the end
      delete front; //deletes front
      front = p; //sets front to the next element
      count--; //incriment down 
      return old; //return it to main
    }
}


//deleteRear()
//Deletes last node. If the queue is empty, an error funtion is called.

template <class T>
T LL<T>::deleteRear()
{
  T old;
  if (isEmpty() == true) //if it is empty, cannot delete, error message
    LLError("The LL is empty. Cannot delete.");
  else if (count == 1)
    { //deleting the rear
      node<T>* p; //new pointer node
      p = front; //let p hold the element to be deleted
      old = front->elem; //will return old front element at the end
      rear = NULL; //rear and front need to be NULL
      front = NULL;
      count--; //incriment down 
      return old; //return it to main
    }
  else
    {
      node<T>* p; //new pointer node
      T old = rear->elem; //element to be returned
      for(p = front; p->next != rear; p = p->next)
	{
	}
      p->next = NULL; //null is next
      rear = p; //front is now p
      count--;
      return old; //return it to main
    }
}


//deleteNode()
//Finds an element in the LL and deletes it.

template <class T>
void LL<T>::deleteNode(const T& e)
{
  if (isEmpty())
    { //if empty, error
      cout << "[ empty ]" << endl;
    }
  else if(front->elem == e)
    { //if the first element is the one to delete
      node<T>* s;
      s = front->next; //point to next
      delete front; //delete front
      front = s; //next is now front
      if (count == 1)
	{ //there is only one element case
	  front = NULL;
	  rear = NULL;
	}
      count--;
    }
  else{ //general case
    node<T>* del;
    node<T>* pre;
    for(pre = front, del = front->next; del!= NULL && del->elem != e; pre = del, del = del->next)
      {
	
      }
    if (del == NULL)
      { //reaches the end of the sequence without finding element
	//nothing will happen
      }
    else if (del != NULL)
      { //element found
	node<T>* s; //new pointer
	s = del->next; //the new next is going to be the spot after the deleted elem
	pre->next = s; //after pre is s
	if (del == rear)
	  { //if the last element is beging deleted
	    s = NULL; //s would be the NULL after rear
	    rear = pre; //pre is new rear
	  }
	delete del; //delete node
	count--;
      }
  }
}


//deleteNodes()
//Finds an element in the LL and deletes all occurances. calls deleteNode() so that there is no duplicate code

template <class T>
void LL<T>::deleteNodes(const T& e)
{
  int static_count = count; //count BEFORE the loop
  for(int counter = 0; counter < static_count; counter++)
    {
      deleteNode(e); //runs deleteNode for every position in the list
    }
}


//isEmpty()
//Checks to see if queue is empty. Returns true or false.

template <class T>
bool LL<T>::isEmpty()
{
  if (front == NULL && rear == NULL)
    return true; //front and rear is NULL, empty
  else
    return false; //not empty
}


//displayAll()
//Prints all elements to the user.

template <class T>
void LL<T>::displayAll()
{
  if (isEmpty() == true)
    {
      cout << "[ empty ]" << endl; //empty display
    }
  else
    {
      node<T>* p; //create p pointer
      p = front; //p points to front
      while (p != NULL)
	{ //loop until p hits a NULL
	  cout<< p->elem << ""; //print elem
	  p = p->next; //p moves up the queue
	}
    }
}


//public - printAllReverse()
//Called in main, calls the similar funtion in the private section of the class.

template <class T>
void LL<T>::printAllReverse()
{
  printAllReverse(front);
}


//private - printAllReverse(node* p)
//Recursive funtion that continuously calls the function until it reaches the end. Once it reaches the end, each element is printed. The end result is all the elements printed in backwards order.

template <class T>
void LL<T>::printAllReverse(node<T>* p)
{
  if (p == NULL)
    return;
  else
    {
      printAllReverse(p->next);
      cout << p->elem;
    }
}


//search()
//searches for an element in the LL. Returns true if it has been found

template <class T>
bool LL<T>::search(const T& e)
{
  if (isEmpty() == true)
    {
      cout << "[ empty ]" << endl; //nothing to search through
    }
  else
    {
      node<T>* p; //create p pointer
      p = front; //p points to front
      while (p != NULL)
	{ //loop until p hits a NULL
	  if (p->elem == e)
	    {
	      return true;
	    }
	  p = p->next; //p moves up the queue
	}
    }
  return false;
}


#endif
