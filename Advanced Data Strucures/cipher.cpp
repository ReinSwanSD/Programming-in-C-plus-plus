/**********************************************************
Reinier Swanepoel
CS211
Kazumi Slott

cipher.cpp

Purpose of this program
You are going to make an application of your myVector class.
You will see if your myVector class works properly.

***********************************************************/

#include <iostream> //needed for cout and fout                                                              
#include <iomanip> //used for fixed                                                                         
#include <cstdlib> //lib for data files   
#include <fstream> //for fin and fout
#include "myVector.h" //input file
#include "checkInput.h" //check input file for get data

using namespace std;

//prototypes

void print(myVector<char>& v);
bool isLetterDigit(char e);
char myToLower(char e);
void cipher(myVector<char>& v);
bool isDigit(char e);

/*********************************

print() function

Prints all contents of a vector char

*********************************/

void print(myVector<char>& v)
{
  for (int i = 0; i < v.size(); i++)
    {
      cout << v[i];
    }
}

/*********************************

isLetterDig() function

Returns true if it is a digit or letter
Returns false if not

*********************************/
bool isLetterDigit(char e)
{
  if (e >= '0' && e <= '9') //digit
    return true;
  
  else if (e >= 'A' && e <= 'Z') //uppercase
    return true;
  
  else if (e >= 'a' && e <= 'z')
    return true;
  
  else
    return false;
}

/*********************************

myToLower() function

for only caps letters
returns uppercase letters and makes them lowercase.

*********************************/
char myToLower(char e)
{
  if (e >= '0' && e <= '9') //digit
    return e;
  
  else if (e >= 'a' && e <= 'z')
    return e;

  else if (e >= 'A' && e <= 'Z') //uppercase
    return (e + 32);
}

/*********************************

cipher() function

cipher the letters by shift and adding number to char

*********************************/
void cipher(myVector<char>& v)
{
  char new_char = 0; //new char to replace v[i]
  int count = 0;  
  bool is_dig;// is true if the element is a digit
  
  cout << endl << endl;
  
  cout << "Enter a secret number to cipher a sentence between 1 and 26: "; //asks user for shift value
  int shift = getData(1, 26, "Invalid response. Please enter a number 1 to 26"); //stores shift value
  
  for (int i = 0; i < v.size(); i++)
    {
      is_dig = isDigit(v[i]); //checks if e is digit
      if (is_dig == false)
	{ //e is a letter
	  
	  if ((v[i] + shift) > 122)
	    { //if the shifted char passes 'z'
	      int shift_counter = 0;
	      new_char = v[i];
	      while (new_char < 122 && shift_counter < shift)
		{ //while new_char hasn't passed z and isn't done with all shifts
		  new_char++; //increase new_char
		  shift_counter++; //increase shifts done
		}
	      if (shift_counter < shift)
		{ 
		  new_char-=26; //wrap back to first letter
		}
	      while (shift_counter < shift) //dont stop shifting until all are done
		{ 
		  new_char++;
		  shift_counter++;
		}
	    }
	  
	  else
	    {
	      new_char = v[i] + shift; //shifts the character secret number of spots
	    }

   
	  v[i] = new_char;
	}

      else 
	{ //e is a digit
	  new_char = v[i] + shift; //shifts the character (shift) number of spots
	  if (new_char > '9')
	    { //if the shifted char passes z
	      while (new_char > '9')
		new_char = new_char - 10; //wraps around
	    }

	  v[i] = new_char;
	}

      //if space is needed, after every 5 letters or digits

      if ((count % 5 == 0) && (count != 0))
	{ //inserts a space after every 5 char
	  v.insert(i,' ');
	  i++;
	}
      count++;
    }
  

  cout << "---- after inserting a space after every 5 characters -----" << endl;
  
  print(v); //prints contents of the ciphered vector array
}

/*************************************************

isDigit(char) function

will return true of item element is a digit
false if not a digit

**************************************************/

bool isDigit(char e)
{
  if (e >= '0' && e <= '9')
    return true;
  else
    return false;
}

/************************************************

main

cipher function

*************************************************/

int main()
{

  string fileName; //user input file                                                                                                                                          
  string sentence; //sentence from file                                                                                                                                       
  myVector<char> c; //to store char in vector                                                                                                                                 
  bool letter_or_digit; //true when char is letter or digit                                                                                                                   
  char lowercase_letter; //element inserted after being checked by myToLower()                                                                                                

  cout << "Enter file name: ";
  cin >> fileName; //cipher1.txt or cipher2.txt                                                                                                                               
  ifstream fin; //just like college.cpp

  fin.open(fileName.c_str());//open file
 
  if (!fin) //file cant be found or open                                                                                                                          
    {
      cout << "Could not open file." << endl; //error
    }

  else//file is found                                                                                                                                                         
    { //the program starts                                                                                                                                                    

      //gets chars and storing them                                                                                                                                           
      getline(fin, sentence); //grabs the line of text                                                                                                                      

      int counter = 0; //create counter for each letter                                                                                                                       

      while (counter != sentence.length())//while the count isnt the last character in string                                                                                 
        {
          c.push_back(sentence[counter]); //push back the char                                                                                                                
          counter++; //go on to next char                                                                                                                                     
        }

      cout << "---- sentence -----" << endl;

      print(c); //prints contents of vector array as regular sentence                                                                                                                             

      for(int i = 0; i < c.size(); i++) //removes spaces
        {
          letter_or_digit = isLetterDigit(c[i]); //check

          if (letter_or_digit == false) //removes non items                                                                                                                   
            {
              c.erase(i);
              i--;
            }
        }

      cout << endl;

      cout << endl << "---- after removing non-letter/digit -----" << endl;

      print(c); //prints contents of vector array as sentence without spaces                                                                                                                             


      for(int i = 0; i < c.size(); i++) //makes all lowercase letters
        {
          lowercase_letter = myToLower(c[i]); //stores output element                                                                                                         
          c[i] = lowercase_letter; //replaces element                                                                                                                         
        }



      cout << endl;

      cout << endl << "---- after converting to lower case -----" << endl;

      print(c); //prints contents of vector array without spaces as lower case letters                                                                                                                             


      cipher(c); //cipher text                                                                                                                                               

      cout << endl <<endl;
      
    }//end of else loop                                                                                                                                                       
  return 0;
}

