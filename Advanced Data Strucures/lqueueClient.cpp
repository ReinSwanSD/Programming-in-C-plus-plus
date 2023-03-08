/****************

Reinier Swanepoel
CS211
Kazumi Slott
lab lqueue vector

********************/
#include <iomanip> //used for fixed                                                                                                          
#include <fstream> //fstream needed for fout and file out                                                                                    
#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this                                                                                   
#include "lqueue.h"
using namespace std;

int main()
{
  LQueue l;
  
  cout << endl;
  
  if (l.isEmpty())
    { //checks isEmpty and outputs findings
      cout << "The queue is empty!" << endl; //this
    }
  else
    {
      cout << "The queue is not empty!" << endl; 
    }
  
  l.displayAll(); //displays all, [ empty ]
  
  l.addRear(1); //adds 1 to rear
  
  l.displayAll(); //displays all, 1
  cout << endl;
  
  l.addRear(2); //adds 2 to rear
  l.addRear(3); //adds 3 to rear
  l.addRear(4); //adds 4 to rear

  l.displayAll(); //displays all, 1 2 3 4
  cout << endl;
  
  cout <<  l.deleteFront() << endl; //delete 1
  cout <<  l.deleteFront() << endl; //delete 2
  cout <<  l.deleteFront() << endl; //delete 3
  
  l.displayAll(); //displays all, 4
  cout << endl;

  if (l.isEmpty())
    { //checks isEmpty and outputs findings
      cout << "The queue is empty!" << endl;
    }
  else 
    {
      cout << "The queue is not empty!" << endl; //this
    }
  
  cout << l.deleteFront() << endl; //delete 4 and display 

  if (l.isEmpty())
    { //checks isEmpty and outputs findings
      cout << "The queue is empty!" << endl; //this
    }
  else
    {
      cout << "The queue is not empty!" << endl; 
    }

  l.displayAll(); //displays all, [ empty ]
  cout << endl;

  return 0;
}
