/*****************************************************************

Reinier Swanepoel
grades.cpp

CS211 Grades Lab

Read data from an input file called “stuscores.dat” that contains the following info. For each student, there are ID, first name, last name and 3 test scores. You can copy this input file from my public directory. Program will output the following into an output file with labels.

***************************************************************/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//prototypes
//void calcLowHighAvg (int & test1, int &test2, int & test3);
void calcLowHighAvg (int  test1, int  test2, int  test3, int &lowest, int&highest, double &average);                                                                       


int main()
{
//variables
  int stuID,test1, test2, test3,lowest,highest;
  string first,last;
  double average;

  ifstream fin; //input file
  ofstream fout; //output file

  fin.open("stuscores.dat");

  if(!fin) // if the input file doesnt exist                                    
    {
      cout<< "The input file doesnt exist" <<endl;
    }
  else // the input file exist and can be read easily                           
    {
      fout.open("grades.out"); //open output file 

      cout<<fixed;                                       
      cout<<setprecision(2);
      
      fout<<setw(5)<<left<<"ID"<<setw(15)<<right<<"Lowest"<<setw(15)<<right<<"Highest"<<setw(15)<<right<<"Average"<<endl;
      
      fin>>stuID;

      while(fin)
	{
	  fin>>first>>last>>test1>>test2>>test3;
	  
	  calcLowHighAvg(test1,test2,test3,lowest,highest,average);
	  

	  fout<<fixed;
	  fout<<setprecision(2);

	  fout<<setw(5)<<left<<stuID<<setw(15)<<right<<lowest<<setw(15)<<right<<highest<<setw(15)<<right<<average<<endl;



	  fin>>stuID;
	}
      fin.close();
      
      fout.close();

    }

  return 0;
}

void calcLowHighAvg (int  test1, int  test2, int  test3, int &lowest, int&highest, double &average)
{
 ////////////////////////////highest 
  if (test1>test2)
    {highest=test1;}
  
  else
    {highest=test2;}
  
  if (test3>highest)
    {highest=test3;}
  //highest done

  ///////////////////////////////////////

  ///////////////////////////lowest
  if (test1<test2)
    {lowest=test1;}
  
  else
    {lowest=test2;}
  
  if (lowest>test3)
    {lowest=test3;}
  //lowest done

  //////////////////////////////////////

  /////////////////////////////average
  average=(double)((test1+test2+test3)/3.00);
		   
		   }

