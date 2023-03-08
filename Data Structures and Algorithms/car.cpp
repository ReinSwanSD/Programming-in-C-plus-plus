/*****************************************************

Reinier Swanepoel
car.cpp

CS111 Lab on files 
template created by Kazumi Slott

This program will pull data from car.dat and display the MPG and the data

*****************************************************/
#include <iostream> //for cout
#include <iomanip> //for setw
#include <fstream> //for files
#include <cstdlib> //for exit
using namespace std;

int main()
{
  //variables declared
  string model; //name of car model
  int miles,gallons,iMiles=0,iGallons=0,count=0; //miles driven and gallons of gas used
  double mpg=0,iMpg=0; //miles per gallon


  //create fin (for an input file)
  ifstream fin;
 
 
  //create fout (for an output file)
  ofstream fout;

  fin.open("car.dat");

  //If the input file doesn't exist, show an error message
  if(!fin) //if (fin == NULL)
    {
      cout<< "Cannot open the input file" << endl;
    }
  else//the input file exists
    {
      fout.open("carout.dat"); //open the output file only if the input file is opened
      
      // VARIABLES DECLARED IN BEGINNING
      //read in 3 values (model, miles, gallons) into variables for the first car
      //      fin >> model; // camry,f150,mustang,altima,neon
      //      fin >> miles; // 123-1322 miles driven
      //      fin >> gallons; //6-86 gallons of gas used

      fout<<"Model Name"<<"\t"<<"\t"<<"Miles Driven"<<"\t"<<"\t"<<"Gallons of Gas Used"<<"\t"<<"\t"<<"MPG"<<endl;

      
      // fout << setw(20)<< left << "Model Name"<< setw(20)<<left<<"Miles Driven"<< setw(20)<<left<<"Gallons of Gas Used"<< setw(10) <<left << "MPG" <<endl;

      fout<<fixed;
      fout<<setprecision(2);

      fin >> model;

      while(fin) //If reading was successful, go inside the while loop
	{
	  //what do you do here?
	 	  
	  fin >> miles >> gallons;
	      
	  mpg = (double)miles/gallons;
	  
	  iMiles=iMiles+miles;
	  
	  iGallons=iGallons + gallons;
	      
	  iMpg =(double) iMpg + mpg;
	  
	  count++;

	  
	  fout << setw(20) << left << model << setw(16) << right << miles << setw(31) <<right << gallons << setw(18) << right << (double)miles/gallons<<endl;

	  fin>>model;	  
	  
	}
      

      fout<<endl;
      
      iMpg=iMpg/count;

      fout<<"Total Miles Driven: "<<iMiles<<" miles"<<endl;
      fout<<"Total Gallons of Gas Used: "<<iGallons<< " gallons"<<endl;
      fout<<"Average MPG: "<<(double)iMiles/iGallons<<" miles per gallon"<<endl;

      //you are done wtih the input file. close it.
      fin.close(); //close the input file

      //you need to do something


      
      //you are done with the output file. close it. 
      fout.close();//close the output file
    }


  return 0;
}
