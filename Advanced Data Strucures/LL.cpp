/*******************************************************

Reinier Swanepoel
LL.cpp
CS211 
Kazumi Slott
Linked List Class

implementation file, define the functions from the header file

*********************************************************/
#include <string>
#include <iostream>
#include "LL.h"
#include <cstdlib>

//PURPOSE:      Constructor which initilizes front, rear, and count
LL::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//PURPOSE:      When the program hits and endbrace '}', delete the LL
//ALGORITHM:    While the LQueue isn't empty, delete front
LL::~LL() 
{
  while (!isEmpty())
    {
      deleteFront();
    }
}

//PURPOSE:      Copies the elements to a new LL array in heap memmory
//ALGORITHM:    While p->next is not NULL, keep looping until last element
LL::LL(const LL& l)
{
  front = NULL; //is NULL
  rear = NULL; //both this front and this rear are null
  count = 0; //this->count is 0
  node* p; 
  p = l.front; //new node points to l.front
  
  while(p != NULL)
    { //loop until->next is null or until the last element
      this->addRear(p->elem); //adds p->elem to the front of list
      p = p->next; //increment p
    }
}





//PURPOSE:      To add en element to the rear of the lqueue
//PARAMS:       the element to add the the lqueue
//ALGORITHM:    if empty, make a new node and set the element. front->next = NULL
//              else, make a new node on rear->next, set the element and set rear
//              ->next to NULL
void LL::addRear(el_t value)
{
  if (isEmpty()==true) //if front and rear are null
    {
      front = new node;
      rear = front;
      front->elem = value;
      front->next = NULL;
      count++;
    }
  else //normal case for general
    {
      rear->next = new node;
      rear = rear->next;
      rear->elem = value;
      rear->next = NULL;
      count++;
    }
}

//PURPOSE:      To delete the front pointer and display the element
//PARAMS:       None
//ALGORITHM:    while the lqueue isn't empty, set a temp element to front->next
//              and deletethe front. Set the temp to the front and return the element
el_t LL::deleteFront()
{
  if (isEmpty())
    {
      queueError("Error: list is empty."); //("UNABLE TO REMOVE FRONT. QUEUE UNDERFLOW.");
     
    }
    
  else
    {
      if (count == 1) //irregular
	{
	  el_t second = front->elem;
	  delete front;
	  front = NULL;
	  rear = NULL;
	  count--;
	  return second;
	}
      else //general
	{
	    node* second = front->next;
	    el_t sec = front->elem;
	    delete front;
	    front = second;
	    count--;
	    return sec;
	}
    }

}

//PURPOSE:      To return if a queue is empty or not (returns true or false)
//PARAMS:       None
//ALGORITHM:    if count is at the initilized state of 0, return true, else
//              return false
bool LL::isEmpty()
 {
  if (front == NULL && rear == NULL)
    return true;
  else
    return false;
 }

//PURPOSE:      To display all the elements in the lqueue
//PARAMS:       None
//ALGORITHM:    While the lqueue isn't empty, put a temp pointer to the front
//              and while the temp->next = NULL, keep displaying and moving
//              the element
void LL::displayAll()
{
  if (isEmpty())
    {
      cout << "[ empty ]" << endl;
    }
  else
    {
      node* p = front;
      while (p != NULL)
	{
	  cout << "[";
	  cout << p->elem;
	  p = p->next;
	  cout << "]" << " ";
	}
      cout << endl;
    }
}

//PURPOSE:      (Private) To handle unexpected errors encountered by other
//              methods
//PARAMS:       String message to be displayed
//ALGORITHM:    'cout' the message and exit program with error code 1
void LL::queueError(string msg)
{
  cout << msg << endl;
  exit(1);
}


//PURPOSE:      To add an node to the front before all other pointers
//PARAMS:       The element you would like to add
//ALGORITHM:    stores the front node in a temp pointer, makes a new pointer
//              in front and sets front->next to the temp pointer
void LL::addFront(el_t elem) 
{
  if (isEmpty())
    {        //if empty, just add to rear
      addRear(elem);
    }
  else
    {      //else, make a new node in front and make the original front
      node* second = front;   //second
      front = new node;
      front->next = second;
      front->elem = elem;
      count++;
    }
}

//PURPOSE:      To delete the rear pointer from the LL
//PARAMS:       None
//ALGORITHM:    determines if the LL has one, none or many elements, then
//              stores the element in a temp variable, sets the rear pointer to
//              NULL and the previous become rear, returns the element
el_t LL::deleteRear()
{
  el_t old;

  if (isEmpty())
    {        //error out if empty
      queueError("UNABLE TO REMOVE REAR. QUEUE UNDERFLOW");
      return 0;
    }
  else
    {
      if (count == 1)
	{       //if only one element, make rear and front NULL
	  node* p; //new pointer node
	  p = front; //let p hold the element to be deleted
	  old = front->elem; //will return old front element at the end
	  rear = NULL; //rear and front need to be NULL
	  front = NULL;
	  count--; //incriment down 
	  return old; //return it to main
	}
      else 
	{
	  node* p; //new pointer node
	  el_t old = rear->elem; //element to be returned
	  for(p = front; p->next != rear; p = p->next)
	    {
	    }
	  p->next = NULL; //null is next
	  rear = p; //front is now p
	  count--;
	  return old; //return it to main
	  
	}
    }
}

//PURPOSE:      To display the lqueue in reverse
//PARAMS:       None
//ALGORITHM:    calls the private function printAllReverse(node* p) with the param
//              'front'
void LL::printAllReverse()
{
  printAllReverse (front);
}

//PURPOSE:      (Private) To display the lqueue in reverse recursively
//PARAMS:       pointer to the first node
//ALGORITHM:    while the pointer isn't NULL, continue to the next pointer
//              if pointer = NULL, return and display element
void LL::printAllReverse(node* p)
{
  if(p == NULL)
    return;
  else
    {
      printAllReverse(p->next);
      cout << p->elem;
    }
}



//PURPOSE:     deleteNode()
//PARAMS:      deleted element
//ALGO:        Finds an element in the LL and deletes it.

void LL::deleteNode(el_t e)
{
  if (isEmpty())
    { //if empty
      cout << "[ empty ]" << endl;
    }
  else if(front->elem == e)
    { //if the first element is the one to delete
      node* s;
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
  else
    { //general case
      node* del;
      node* pre;
      for(pre = front, del = front->next; del!= NULL && del->elem != e; pre = del, del = del->next)
	{//keeps looping until found
	}
      if (del == NULL) //elem not found
	{ 
	  //nothing 
	}
      else if (del != NULL)
	{ //element found for general case
	  node* s; //new pointer
	  s = del->next; //the new next is going to be the spot after the deleted elem
	  pre->next = s; //skip the deleted elem
	  if (del == rear)//if last elem of LL
	    { 
	      s = NULL; //s would be the NULL after rear
	      rear = pre; //pre is new rear
	    }
	  delete del; //delete node
	  count--;
	}
    }
}


//PURPOSE:         deleteNodes()
//PARAMS:          searched elem to be deleted
//ALGO:            Finds an element in the LL and deletes all occurances. 

void LL::deleteNodes(el_t e)
{/*
  int temp_count = count; //count of nodes
  for(int counter = 0; counter < temp_count; counter++)
    {
      deleteNode(e); //runs deleteNode for every node in LL, will only delete if matches
    }
 */
    
  if (!isEmpty()) 
    {
      bool found = false;
      node* pre = front;
      node* del = front->next;
      
      while (del != NULL)
	{
	  if (del->elem == e)
	    {
	      pre->next = del->next;
	      if (del == rear)
		rear = pre;
	      delete del;
	      found = true;
	      count--;
	    }
	  else
	    pre = pre->next;

	  del = pre->next;
	}
      if (front->elem == e)
	{
	  deleteFront();
	  found = true;
	}
    }
  
  
}


//PURPOSE:         search()
//ALGO:            searches for an el. Returns true if found

bool LL::search(el_t e)
{
  int count = 0;
  if (isEmpty() == true) //ifempty
    {
      cout << "[ empty ]" << endl; //nothing to search through
    }
  else//general
    {
      node* p; //created p pointer
      p = front; //p points to first node elem
      while (p != NULL)
	{ //loop until p hits the rear element or NULL
	  count++;
	  if (p->elem == e)
	    {
	      cout << count << " NODES CHECKED" <<endl;
	      return true; //exits
	    }
	  p = p->next; //p moves up to next node
	}
      cout << count << " NODES CHECKED" << endl;
    }
  return false;
}

void LL::addInOrderAscend(el_t el)
{
  if (count == 0) //if empty
    { //first element (add front)
      front = new node; //creates a new node for front
      rear = front; //rear will = the front
      front->elem = el; //front elem is inserted
      rear->next = NULL; //front next == NULL
      count++;
    }
  else if (el < front->elem) 
    {//if el needs to go first (add front)
      node* p;
      p = new node;
      p->elem = el;
      p->next = front;
      front = p;
      count++;
    }
  else if (el > rear->elem)
    { //if el needs to go last (add rear)
      rear->next = new node; //new node
      rear = rear->next; //rear points to new node
      rear->elem = el; //insert element
      rear->next = NULL;
      count++;
    }
  else //general
    {
      node* pre;
      node* post;
      node* e;
      e = new node;
      e->elem = el;
      pre = front;
      while (pre->next != NULL && pre->next->elem < el)
	{//front keeps shifting until acend order
	  pre = pre->next;
	}
      post = pre->next;
      pre->next = e;
      e->next = post;
      count++;
    }
}
