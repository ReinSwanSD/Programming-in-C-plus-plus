/********************************************************
CS111 Lab on c-strings
Template prepared by Kazumi Slott
********************************************************/
#include <iostream>
using namespace std;

void myStrcat(char dest[], const char source[]);

int main()
{
  char str2[80] = "Dave ";
  cout <<str2 <<endl;
  myStrcat(str2, "Smith");
  cout << str2 << endl; //Dave Smith

  return 0;
}

void myStrcat(char dest[], const char source[])
{
  int d=0;
  int j=0;
  //Move d to the end of dest ('\0')
  for(d=0; dest[d] != '\0';d++)
    {
    }

  //copy each character from source to dest
  for (j=0; source[j] != '\0';j++,d++)
    {
      dest[d]=source[j];
    }

  //place '\0' at the end of dest
  dest[d]='\0';


}
