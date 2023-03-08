#include <iostream>
using namespace std;

int main()
{

  int* P1;
  int* P2;
  
  P1=new int;

  int a=1;
  *P1=a;
  
  cout<< *P1 <<endl;

  P2=new int;
  int b=2;
  *P2=b;

  cout<< *P2 <<endl;
  
  delete P2;
  
  P2=P1;
  
  cout<<*P2<<endl;

  delete P2;

  P1=NULL;

  P2=new int;
  int c=3;
  *P2=c;

  cout<<*P2<<endl;

  return 0;
}
