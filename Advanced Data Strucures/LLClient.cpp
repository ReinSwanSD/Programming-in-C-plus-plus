/***************************

Reinier Swanepoel
LLClient.cpp                                                                                                                   
CS211                                                                                                                    
Kazumi Slott                                                                                                             
Linked List Class                                                                                                        
                                                                                                                         
Client program
                                                                                                                         
*********************************************************/
#include <string>
#include <iostream>
#include "LL.h"
#include <cstdlib>
using namespace std;


int main()
{
  //part 1
  LL l1;

  l1.addFront(1); //1

  l1.addFront(2); //2 1

  l1.addFront(3); //3 2 1

  l1.addRear(4); //3 2 1 4

  l1.addRear(5); //3 2 1 4 5

  l1.displayAll(); // 32145 all on same line

  cout << endl; //proper spacing

  cout << l1.deleteFront() << " has been deleted" << endl; //3

  cout << l1.deleteRear() << " has been deleted" << endl; //5

  l1.displayAll(); // 214

  cout << endl; //proper spacing

  cout << l1.deleteFront() << " has been deleted" << endl; //2

  cout << l1.deleteRear() << " has been deleted" << endl; //4

  l1.displayAll(); // 1

  cout << l1.deleteFront() << " has been deleted" << endl; //1                                                          

  l1.displayAll(); // empty                                                                                                  
  l1.addRear(10); //10

  l1.addFront(11); //11 10

  l1.displayAll(); // 11 10 all on same line

  cout << endl; //new line

  cout << l1.deleteRear() << " has been deleted" << endl; //10

  cout << l1.deleteRear() << " has been deleted" << endl << endl; //11

  l1.displayAll(); // empty                                                                                             

  //part 2
  //copy constructor
  LL a; //create heap

  a.addRear(1); //adds 1

  a.addRear(2); //adds 2

  cout << endl; //new line

  LL b(a); //new copied link list in heap

  b.displayAll(); //display b 1 2

  cout << endl; //new line

  cout << a.deleteFront() << " has been removed" << endl; //1

  a.displayAll(); //display a 2

  cout << endl; //proper spacing

  b.displayAll(); // 1 2

  cout << endl; //proper spacing

  return 0;
}


