/*************************                                            
Reinier Swanepoel                                                                                    
CS211                                                                                                
Kazumi Slott                                                                                         

Palindrome.cpp

Client program
“A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward or
forward.”

*********************************************************/

#include <string>
#include <iostream>
#include "LL.h"
#include <cstdlib>
#include <fstream>
#include "myStrCharFunc.h"

using namespace std;


//prototypes

void createLL(LL& l, string s);
bool palidrome(LL& l, string s);

int main()
{
  string s; //string of chars from dat file
  LL l; //linked list
  bool is_palindrome; //true or false for is palindrome

  //ask user for sentence 
  /*
  cout << "Enter a sentence: ";
  getline(cin, s);
  */
  
  ifstream fin; //just like college.cpp                                                                                                                                                                    
  fin.open("palindrome.dat");//open file                                                                                                                                                                      
  while (!fin.eof())
    { //loops until end

      getline(fin, s); //or (cin,s) if entered

      createLL(l, s); //testing LL with add front

      is_palindrome = palidrome(l, s);

      if (is_palindrome == true)
	{ //if palindrome
	  cout << "\"" << s << "\" is a palindrome" << endl;
	}
      else
	{ //false if not
	  cout << "\"" << s << "\" is not a palindrome" << endl;
	}
      //getline(fin, s); //doesnt work use .eof()
      
    }
  return 0;
}

/*****************************************************

createLL() 

Use add front to see if it works, construct a linked list from the string
minus spaces and punctutations

******************************************************/
void createLL(LL& l, string s)
{
  for(int i = 0; i < s.length(); i++)
    {
      if (isLetter(s[i]) == true) // if letterr
	{
	  l.addFront(myToLower(s[i])); //add to LL
	}
    }
}

/*******************************************************

palindrome() 

bool using the functions you already have
checking to see if palindrome

pass link listed and sentence

*********************************************************/
bool palidrome(LL& l, string s)
{
  string s1, s2;
  char cc;
  
  for(int i = 0; i < s.length(); i++)//first string
    {
      if (isLetter(s[i]) == true)
	{
	  s1 = s1 + myToLower(s[i]);
	}
    }

  while (!l.isEmpty()) //linked list string
    {
      cc = l.deleteFront();
      s2 = s2 + cc;
    }
  //will return the correct bool
  if (s1 == s2)
    return true; //if matches
  else 
    return false; //if not a palindrome
}
