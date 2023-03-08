/*******************************************************************************

Reinier Swanepoel
Struct
4/28/2020

this program will organize data from the input file employees.dat information 
using struct

*******************************************************************************/
#include <iostream>
#include <iomanip> //for setw
#include <fstream> //for files
#include <cstdlib> 
#include <string>
#include <stdlib.h>

using namespace std;

struct employee
{
  string firstName;
  string lastName;
  char gender;
  double hourlyRate;
  int empID;
  int age;
};
//function prototype
int readData(struct employee[]);
void findMale(employee empAr[],int numEmp);
void printEmployee(employee & numEmp);
void printAllEmployee(employee empAr[], int numEmp);
employee findOldest(employee empAr[], int numEmp);
void giveRaiseToAll(employee empAr[],double per,int numEmp);
void giveRaiseToOneEmp(employee empAr[],double per,int numEmp);
int femaleArray(employee empAr[], employee fAr[], int numEmp);
void findEmp(employee empAr[], int numEmp);
void sortEmployees(employee empAr[], int numEmp);

//main function
int main()
{
  //Declaring constant value
  const int MAX_EMP = 100;

  //Array of structure employee objects
  struct employee empAr[MAX_EMP];
  struct employee fAr[MAX_EMP];

  //Variable to hold the count of employees
  int numEmp;
  employee oldest;
  double per;
  //Read data and find number of records exist in the file
  numEmp = readData(empAr);
  cout<<endl<<"----------------------readData()--------------------------" <<endl;

  //Display employee count
  cout << "\n\nThere are " << numEmp << " employees."<<endl;
  cout<<endl<<"----------------------findMale()--------------------------" <<endl; 
  //read data and find number of M in the file
  findMale(empAr, numEmp); //displayed in maleOut.dat
  cout << endl << "----------------------printEmployee()---------------------" << endl;
  printEmployee(empAr[0]);
  cout<<endl<<"----------------------printAllEmp()--------------------------" <<endl;
  printAllEmployee(empAr,numEmp);
  cout <<endl<<"------------------------- findOldest() ---------------------- "<<endl;
  oldest=findOldest(empAr,numEmp);
  cout<<oldest.firstName<<endl;
  cout << endl << "--------------------giveRaiseToAll()-----------------------" << endl;
  per=5.50;
  giveRaiseToAll(empAr,per,numEmp);
  printAllEmployee(empAr,numEmp);
  cout << endl << "----------------------giveRaiseOneEmployee()--------------" << endl;
  per=2.0;
  giveRaiseToOneEmp(empAr,per,numEmp);
  printEmployee(empAr[1]);
  cout << endl << "---------------------femaleArray()-------------------------"<<endl;

  int f=femaleArray(empAr,fAr,numEmp);
  cout<<"There are "<< f << " females."<<endl;
  cout <<endl;
  for(int i=0;i<f;i++)
  printEmployee(fAr[i]);
  cout << endl << "--------------------- findEmp() ---------------------------"<<endl;
  findEmp(empAr, numEmp);
  cout <<endl;
  findEmp(empAr, numEmp);
  cout <<endl;
  findEmp(fAr, numEmp);
  cout <<endl<< "--------------------- sortEmployees() -------------------"<<endl;
  sortEmployees(empAr, numEmp); // sort the employees
  printAllEmployee(empAr, numEmp); // call printAllEmp function to print the employee 

  return 0;

}

/*****************************************************************

function that reads data from the user and stores it in an array
keeping count of the employees you have
return num;

*****************************************************************/

int readData(struct employee empAr[])
{
  int num = 0;

  //Opening file
  ifstream fin; //("employees.dat")

  fin.open("employees.dat");

  //Check for existence of file
  if(!fin)
    {
      cout<<"\n\n Error!!!! File doesn't exist";
      return 0;
    }
 

  //Read data and increment num variable
  fin >> empAr[num].firstName;// loop it like car.out?>?
  while(fin)//while(fin)????
    {
      //fin >> empAr[num].firstName; 
      fin >> empAr[num].lastName;
      fin >> empAr[num].gender;
      fin >> empAr[num].hourlyRate;
      fin >> empAr[num].empID;
      fin >> empAr[num].age;
      
      num++;

      fin >> empAr[num].firstName;

    }
    

  //Close file
  fin.close();
  
  //Return number of records read
  return num;
}

/***************************************************************

This function will find all male employee ids and first and last names and output it in correct format

****************************************************************/

void findMale(employee empAr[],int numEmp)
{
  ofstream fout;
  
  fout.open("maleOut.dat"); //create output file
  
  for(int i = 0; i < numEmp; i++)
    {
    if(empAr[i].gender == 'M')
      fout<<setw(10)<<empAr[i].empID<<setw(10)<<empAr[i].firstName<<setw(10)<<empAr[i].lastName<<endl;
    }
  fout.close();
}

/******************************************************************

This function will pass ONE employee information as a parameter and display
all the information about the employee on the screen as formated.

******************************************************************/
void printEmployee(employee & numEmp)
{
  {
    cout <<left<<setw(10)<<numEmp.firstName<<setw(10)<<numEmp.lastName<<setw(10)<<numEmp.gender<<setw(10)<<numEmp.hourlyRate<<setw(10)<<numEmp.empID<<setw(10)<<numEmp.age<<endl;
    }

}

/******************************************************************

This function will pass ALL employees information as a parameter and display
all the information about the employee on the screen as formated.

******************************************************************/

void printAllEmployee(employee empAr[], int numEmp)
{
  for(int i=0; i<numEmp;i++)
    {
      cout<<fixed;
      cout<<setprecision(2);


      cout <<left<<setw(10)<<empAr[i].firstName<<setw(10)<<empAr[i].lastName<<setw(10)<<empAr[i].gender<<setw(10)<<empAr[i].hourlyRate<<setw(10)<<empAr[i].empID<<setw(10)<<empAr[i].age<<endl;
    }
}

/*****************************************************************

This function will find the oldest in the array and return the whole struct 
to the caller.

******************************************************************/

employee findOldest(employee empAr[], int numEmp)
{
  int old_index = 0; // initializing old_index value with first employee index
  int i;
  for(i=1; i< numEmp; i++)
    {
      // if current employee is older than curent oldest
      if(empAr[i].age > empAr[old_index].age)
	old_index = i;
    }  
      
      return empAr[old_index];
    
}

/*********************************************************************

This function will give raise to all.

**********************************************************************/

void giveRaiseToAll(employee empAr[],double per,int numEmp)
{

  int i;
  for(i=0; i<numEmp; i++)
    {
      empAr[i].hourlyRate = empAr[i].hourlyRate + empAr[i].hourlyRate*per/100.0;
    }
}

/*****************************************************************

This function will give raise to one employee 

*******************************************************************/


void giveRaiseToOneEmp(employee empAr[],double per,int numEmp)
{

  int i;
  for(i=0; i<numEmp; i++)
    {
      if(i==1)
      empAr[i].hourlyRate = empAr[i].hourlyRate + empAr[i].hourlyRate*per/100.0;
    }
}


/**************************************************************

 Make a function called femaleArray that will store all the female employees into a different array.

************************************************************/

int femaleArray(employee empAr[], employee fAr[], int numEmp)
{
  int females=0;
  for(int i = 0; i < numEmp; i++)
    {
      if(empAr[i].gender == 'F')
	{
	  fAr[i].gender = empAr[i].gender;
	  females++;
	}
    }
  return females;
}

/**************************************************************

This function will find the employee with a particular id

**************************************************************/

void findEmp(employee empAr[], int numEmp)
{

  bool found = false;
          

  int id;

  cout<<"Enter the Employee id: ";

  cin>>id;

  for(int i=0; i<numEmp && found==false ; i++)
    {
      
      if(empAr[i].empID==id)
	{
	  
	  cout<<empAr[i].firstName<<"\t"<<empAr[i].lastName<<endl;
	  
	  found=true;
	  
	}             
    } 
  if(found==false)              

    cout<<"There is no employee with ID: "<<id<<endl;

}

/*******************************************************************

This function will be sorting in alphabetical order

******************************************************************/

void sortEmployees(employee empAr[], int numEmp)
{
  int i, j, min_idx;
  employee e;
  // iterate through the elements in the array
  for (i = 0; i < numEmp-1; i++)
    {
      // Find the index of the minimum element in array
      min_idx = i;
      for (j = i+1; j < numEmp; j++)
	if (empAr[j].firstName < empAr[min_idx].firstName)
	  min_idx = j;
      
      // Swap the found minimum element with the first element
      e = empAr[min_idx];
      empAr[min_idx] = empAr[i];
      empAr[i] = e;
    }
}
