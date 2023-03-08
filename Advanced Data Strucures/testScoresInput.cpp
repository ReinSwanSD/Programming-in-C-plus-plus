/**********************************************************

Reinier Swanepoel
TestScoresInput.cpp

CS211 excercise 6 of input files

Make a C++ program using an input file, compile, and run
(write a program that will read the data from the input file and output the name and averagee score for each student in the same format as below
place all code in the main, if the file doesnt exist, show an error message to the screen)

**********************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
  string student;//name of student
  int score1,score2; //first number and second number of score
  double average; //average of both scores

  //create fin (for an input file)

  ifstream fin;

  //create fout (for an output file)

  // ofstream fout;

  fin.open("scores.dat");

  if(!fin) // if the input file doesnt exist
    {
      cout<< "The input file doesnt exist" <<endl;
    }
  else // the input file exist and can be read easily
    {
      cout<<fixed; //fin or fout? or cout
      cout<<setprecision(1);
     //  fout.open("scores.dat"); // open output file
      fin>>student;

      while(fin)
	{

	  fin>>score1>>score2;
	  average=(double)(score1+score2)/2;
	  cout<<setw(10)<<left<<student<<setw(5)<<right<<average<<endl;
	  fin>>student;
	}
      fin.close();
    }
	 

  return 0;
}
