/*******************************************************
Reinier Swanepoel
cat.cpp

Makethefollowingprogram.Compileitandrunit.Youwillnotseeanythingeasierthanthisonthefinalexam.
*******************************************************/

#include <iostream>
#include <iomanip> 
#include <fstream> 
#include <cstdlib>
#include <string>
#include <stdlib.h>

using namespace std;
//declareastruct calledcatthathasname (string) andgender(char) fields
struct cat
{
  string name;
  char gender;

};

void fillAr(cat ar[],int size);
void printAr(cat ar[], int size);

int main()
{
  //declareaconstantSIZEsetto3
  const int SIZE=3; //not changing/constant
  //Makeanarrayofcatsthathas SIZEslots
  struct cat ar[SIZE];
  //CallfillAr
  fillAr(ar, SIZE);
  //CallprintAr
  printAr(ar, SIZE);

  return 0;
}
void fillAr(cat ar[],int size)
{
  //fillthearrayusingcin inthesameformatasthesamplerunbelow
  for (int i=0; i < size ; i++)
    {
      cout<<"Enter the name of cat "<<i+1<<":";
      cin>>ar[i].name;

      cout<<"Enter the gender of cat "<<i+1<<":";
      cin>>ar[i].gender;
      cout<<endl;
    }

}

void printAr(cat ar[], int size)
{
  //printtheinformationofallthecatsinthefollowingformat
  for (int i=0; i < size ; i++)
    {
      cout<<left<<setw(10)<<ar[i].name<< ar[i].gender<<endl;

    }

  cout<<endl;

}

