/******************************************************************************

Reinier Swanepoel
4/29/2020
carClass

******************************************************************************/

#include <iostream>
using namespace std;

enum direc {NORTH, EAST, SOUTH, WEST}; //array with direction, values 0 1 2 3
//private:
class Car //class name, usually capitolize the first letter
{
private: //private section with attributes
  string make;
  string model;
  int year;
  int vin;
  int mileage;
  string color;
  string type;
  int x; //int (left or right)
  int y; //int (up or down)
  direc direction; //data type direc
  
public: //public section with behaviors
  Car(string md, int yr);
  string getMake()const;
  string getModel()const;
  int getMileage()const;
  void turnRight();

  void turnLeft();
  string getDirection()const;
  void goForward(int blocks);
  //void goBack();
  void getLocation()const;
  int getX()const;
  int getY()const;
};

string Car::getMake()const
{
  return make;
}

string Car::getModel()const
{
  return model;
}

int Car::getMileage()const
{
  return mileage;
}

void Car::turnRight()
{
  if(direction == WEST)
    direction = NORTH;
  else
    direction =(direc)(direction+1);
}

void Car::turnLeft()
{
  if(direction == WEST)
    direction = SOUTH;
  else
    direction=(direc)(direction+3);
}

string Car::getDirection() const
{
  switch(direction)
    {
    case NORTH: return "north";
    case EAST: return "east";
    case SOUTH: return "south";
    case WEST: return "west";
    }
}

void Car::goForward(int blocks) //reg function, isnt returning value just void
{
  if(direction == EAST)
     {
       x = x+blocks;
       mileage=mileage+blocks;
     }
  else if(direction == NORTH)
    {
      y= y+blocks;
      mileage=mileage+blocks;
    }
  else  if(direction == SOUTH)
    {
      y=y-blocks;
      mileage=mileage+blocks;
    }
  else//west
    {
      x=x-blocks; //or x-=blocks
      mileage=mileage+blocks;
    }
}

void Car::getLocation()const
{
  cout<<endl<<"("<<x<<", "<<y<<")"<<endl;
}
//constructor belongs to car class
Car::Car(string md, int yr)
{
  year=yr;
  //  make=mk;
  model = md;
  mileage = 0;
  x = 0;
  y =0;
  direction = NORTH;
}

int Car::getX()const
{
  return x;
}

int Car::getY()const
{
  return y;
}
int main ()
{
  Car c1("Camry",2021); // model , year
  Car c2("Corolla",2021);

  cout<<c1.getModel()<<endl;
  //cout<<c2.getModel()<<endl;

  //cout<<c1.getDirection()<<endl;
  c1.goForward(3);
  c1.turnRight();
  c1.goForward(5);
  c1.turnRight();
  c1.goForward(7);
  c1.turnRight();
  c1.goForward(6);
  c1.turnLeft();
  c1.goForward(1);
 
  //cout<<c1.getDirection()<<endl;
  //c1.turnLeft();
  //cout<<c1.getDirection()<<endl;



  //c1.goForward(3);
  //c1.getLocation();

  cout<<"("<<c1.getX()<<", " << c1.getY() <<")"<<endl;
  cout<<"Mileage = "<<c1.getMileage()<<endl;
  //cout<<c1.getX <<c1.getY<<endl wont work since we are outside the private
  return 0;
}
