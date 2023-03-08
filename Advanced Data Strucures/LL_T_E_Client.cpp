/**********************

Reinier Swanepoel
CS211
kazumi Slott

Test Client for try catch and throw

*************************/

#include <iostream>
#include <string>
#include "LL_T_E.h"

using namespace std;
int main()
{
  LL<int> l;

  try
    {
      cout << "delete rear testing..." << endl;
      
      l.addFront(9);
      l.addFront(8);
      
      l.displayAll(); //9 8
      cout << endl;
      
      cout <<"Removed "<< l.deleteRear() << endl;
      cout <<"Removed "<< l.deleteRear() << endl;
      
      cout <<"Removed "<< l.deleteRear() << endl;
      
    }
  
  catch(LL<int>::Underflow)
    {
      cout << "ERROR: UNDERFLOW. CANNOT DELETE REAR BECAUSE NOTHING TO DELETE" << endl;
    }
  
  
  try {
    cout << "delete front testing..." << endl;
    
    l.addFront(7);
    l.addFront(6);
    
    l.displayAll(); //7 6
    cout << endl;
    
    cout <<"Removed "<< l.deleteFront() << endl;
    cout <<"Removed "<< l.deleteFront() << endl;
    
    cout <<"Removed "<< l.deleteFront() << endl;
  }
  
  catch(LL<int>::Underflow)
    {
      cout << "ERROR: UNDERFLOW. CANNOT DELETE FRONT BECAUSE NOTHING TO DELETE" << endl;
    }
  
  
  return 0;
}
