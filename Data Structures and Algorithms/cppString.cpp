/*****************************************************************************
Template prepared by K. Slott
11-22-2017

This program will read email addresses from email.dat and extract the username and department for each person.

email.dat  (userName.dep@csusm.edu) 
-------------
kslott.cs@csusm.edu
wu.cs@csusm.edu
puha.math@csusm.edu
price.phy@csusm.edu
harrison.eng@csusm.edu
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
  string email;
  string username;
  string department;
  //string space;
  int pos1,pos2,pos3;
  ifstream fin;
  ofstream fout;
  //add more variables as you need them

  fin.open("email.dat");

  if(!fin)
    cout << "The input file doesn't exist" << endl;

  else //the input file exists
    {
      fout.open("Result.dat");

      fin >> email;

      while(fin)
	{//kslot.cs@csusm.edu
	  pos1=email.find(".")+1; //6+1=7
	  pos2=email.find("@"); //9
	  pos3=pos2-pos1; //email.find("@")-email.find("."); 9-7=2
	  //extract the username and department and cout them.
	  username=email.substr(0,email.find("."));
	  department=email.substr(email.find(".")+1,pos3);
	  //space=email.substr(pos2,pos3);
	  fout<< username << " at " << department<<endl;
	 

	  fin >> email;
	}

      fin.close();
    }

  return 0;
}





