/****************************

Reinier Swanepoel 
price.h

****************************/
#ifndef PRICE_H
#define PRICE_H
#include <iostream>
using namespace std;

class Price
{
  friend ostream& operator<<(ostream& o, const Price&z);



 private:
  
  int dollar;
  int cent;
  
  

 public:
  Price();
  Price(int d, int c);
  
  int getDollars() const;
  int getCents() const;
  
  Price operator+(const Price& z);
  Price operator-(const Price& z);
  
    
};
#endif //PRICE_H
