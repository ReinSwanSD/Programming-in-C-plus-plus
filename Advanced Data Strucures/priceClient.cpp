/*****************

Reinier Swanepoel
priceClient.cpp

*****************/
#include <iostream>
#include "price.h"
using namespace std;

int main()
{
  Price p1(2, 50); Price p2(3, 75); Price p3(1,99); Price p4(1,58);
  Price total1 = p1 + p2;
  Price total2 = p1 + p1;
  Price total3 = p1 + p4;
  
  Price diff1 = p2 - p1;
  Price diff2 = p1 - p3;
  /*
  cout << "$" << p1.getDollars()<<"."<<p1.getCents() << "+$" << p2.getDollars()<<"."<<p2.getCents() << "=$" << total1.getDollars()<<"."<<total1.getCents()<< endl; //$2.50+$3.75=$6.25
  cout << "$" << p1.getDollars()<<"."<<p1.getCents() << "+$" << p1.getDollars()<<"."<<p1.getCents() << "=$" << total2.getDollars()<<"."<<total2.getCents()<< endl; //5.00
  cout << "$" << p1.getDollars()<<"."<<p1.getCents() << "+$" << p4.getDollars()<<"."<<p4.getCents() << "=$" << total3.getDollars()<<"."<<total3.getCents()<< endl; //4.08
  cout << "$" << p2.getDollars()<<"."<<p2.getCents() << "-$" << p1.getDollars()<<"."<<p1.getCents() << "=$" << diff1.getDollars()<<"."<<diff1.getCents()<< endl;//1.25
  cout << "$" << p1.getDollars()<<"."<<p1.getCents() << "-$" << p3.getDollars()<<"."<<p3.getCents() << "=$" << diff2.getDollars()<<"."<<diff2.getCents()<< endl;//0.51
*/
  cout << "$" << p1 << "+$" << p2 << "=$" << total1 << endl; //$2.50+$3.75=$6.25
  cout << "$" << p1 << "+$" << p1 << "=$" << total2 << endl; //$2.50+$2.50=$5.00
  cout << "$" << p1 << "+$" << p4 << "=$" << total3 << endl; //$2.50+$1.58=$4.08
  cout << "$" << p2 << "-$" << p1 << "=$" << diff1 << endl; //$3.75-$2.50=$1.25
  cout << "$" << p1 << "-$" << p3 << "=$" << diff2 << endl; //$2.50-$1.99=$0.51


  return 0;
}
