/*******

Reinier Swanepoel
CS211
Kazumi Slott

ABET add ascending order- not using any already made functions

***********/


#include <iostream>
using namespace std;
#include "LL.h"

int main()
{
  LL l;
  
  l.displayAll(); //empty
  
  cout << endl;

  l.addInOrderAscend(3); //3
  
  l.displayAll(); //3
  
  cout << endl;

  l.addInOrderAscend(1); //1 3

  l.displayAll(); //1 3
  
  l.addInOrderAscend(2); //1 2 3

  l.displayAll(); //1 2 3
  
  cout << endl;
  
  l.addInOrderAscend(4); // 1 2 3 4
  
  l.displayAll(); //1 2 3 4

  cout << endl;

  l.addInOrderAscend(2);//1 2 2 3 4

  l.displayAll(); //1 2 2 3 4
  
  cout << endl;
  
  return 0;
}
