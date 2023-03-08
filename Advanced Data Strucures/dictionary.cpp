/**************************************************************

Reinier Swanepoel
CS211
Kazumi Slott

Dictionary.cpp

Application that will use LL class and use essay.txt and use badwords.txt, create dictionary directory,
All the words will be put into LL without duplicates.

**************************************************************/
//includes
#include <iostream>//cin and cout
#include <string> //all string compands
#include <fstream> //fin
#include "LL.h" //for linked lists
#include "utility.h" //for myStrChar functions

using namespace std;

//prototypes
void buildLL(LL& l);
string stripStr(string w); //not passing an object so no &
void removeBadWords(LL& l);
void outputToFile (LL& l);

int main()
{
  LL words; //Linked List variable

  buildLL(words); //calling build LL

  removeBadWords(words); //calling removed bad words

  outputToFile(words); //display to files
  
  return 0;
}


//// stripStr() - takes a word from buildLL() and excludes special characters and makes letters lowercase
//// the new string is the new word thats lowercase and without punctuations added to the ll

string stripStr(string w)
{
string temp = ""; //new string variable
for(int i = 0; i < w.length(); i++)
  { //for each character
if (isLetter(w[i]) == true)
  { //add the char to make the new word
temp = temp + myToLower(w[i]); //stripped and lowercase version is added to new word
}
}
return temp; //new word is returned
}


//buildLL()-takes words from essay and arranged it in order alphabetical only if lowered and no symbols,
//nothing is returned

void buildLL(LL& l)
{
  string word;
  string l_word;
  ifstream input("essay.txt"); //opens file
 
  if (!input.is_open())
    { //tests if file is found
      cout << "Error: File not found" << endl; //not found/opened
    }
  else
    { //if file did open and found
      
      while (!input.eof())
	{ //read until the end
	  input >> word;
	  if (isLetter(word[0]) == true) //only words
	    { 
	      l_word = stripStr(word); //lowercases and removes punctuation
	      if (l.search(l_word) == false)
		{ //if word is already in LL, dont inlcude it
		  l.addInOrderAscend(l_word); //add to LL in order
		}
	    }
	}
    }
  input.close(); //closes file
}


//removeBadWords();removes words found in badWords.txt from the LL.
//nothing is returned

void removeBadWords(LL& l)
{
  string word;
  ifstream input("badWords.txt"); //open bad words file
  
  if (!input.is_open())
    { 
      cout << "Error:File not found." << endl; //failed
    }
  else
    {
      //success
      while (!input.eof())
	{ //goes to the end of file
	  input >> word; //stores bad word
	  if (l.search(word) == true)
	    { //searches for bad word
	      l.deleteNode(word); //delete all times it appears
	    }
	  input.ignore(); //ignores space
	}
    }
  input.close(); //closes file
}


//outputToFile()- outputs every word to the dictionary if not a bad word, arranged by first letter
//nothing is returned,file letter is A

void outputToFile (LL& l)
{
  string s;
  char fileNameLetter;
  string fileName = "./dictionary/?.txt";
  ofstream output; //opens the output files
  
  s = l.deleteFront(); //takes first word

  fileNameLetter = myToUpper(s[0]); //replace the ? in fileName and compare to other first letters in the following cases
  fileName[13] = fileNameLetter; //replaces ? in fileName

  output.open(fileName.c_str()); //opens
  output << s << endl; //output to proper file

  while (!l.isEmpty())
    { //keep going until all done
      s = l.deleteFront();
      if (fileNameLetter != myToUpper(s[0]))
	{ 
	  output.close(); //close file
	  fileNameLetter = myToUpper(s[0]); //new first letter for file
	  fileName[13] = fileNameLetter;
	  
	  output.open(fileName.c_str()); //open file under new letter
	}
      output << s << endl; //output to file
    }
  output.close(); //close last file
}
