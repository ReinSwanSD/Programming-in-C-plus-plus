/**********************************************************

Reinier Swanepoel
CS 211
College.cpp

This function will apply student class, price class and array.h to make a running application called college.
Choose either Admin or student for list of functions to perform.

*********************************************************/

#include <iomanip> //used for fixed                                                       
#include <fstream> //fstream needed for fout and file out                                 
#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this

using namespace std;

#include "/cs/slott/cs211/checkInput.h"
#include "array.h"
#include "student.h"

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

int showMenu();
int showAdmMenu();
int showStuMenu();
void addStu(Student stuAR[],int& co, int& cID);
void showStuInfo(const Student s);
void allStuInfo(Student stuAR[], int co);
bool operator==(const Student& s, int id);
void addStuFromFile(Student stuAR[],int& co, int& cID);
void removeStu(Student stuAR[],int& co);
void addCourse(Student& s);
void dropCourse(Student& s);
void makePayment(Student &s); 
bool checkPassword(int true_pass); 
int findStu(Student s[], int n, int id);

int main()
{
  int count = 0; 
  int curID = START; 
  Student ar[SIZE]; 
  int m_menu; 
  int s_menu; 
  int a_menu;
  bool p_check;
  int u_id; 
  int user_pass;
  int id_check; 
  
  do {
    m_menu = showMenu();
    switch (m_menu)
      {
      case 1: 
	{
	  p_check = checkPassword(123);
	  if (p_check == true)
	    {
	      do {
		a_menu = showAdmMenu();
		
		switch (a_menu)
		  {
		  case 1:
		    { 
		      addStu(ar, curID, count);
		      break;
		    }
		  case 2:
		    { 
		      addStuFromFile(ar, count, curID);
		      break;
		    }
		  case 3:
		    {
		      removeStu(ar, count);
		      break;
		    }
		  case 4:
		    {
		      cout << "Enter the student id: ";
		      cin >> u_id;
		      id_check = findStu(ar, count, u_id);
		      if (id_check != -1)
			showStuInfo(ar[id_check]);
		      break;
		    }
		  case 5:
		    {
		      allStuInfo(ar, count);
		      break;
		    }
		  case 6:
		    {
		      
		      break;
		    }
		  }
	      }while(a_menu != 6);
	    }
	  break;
	}
    case 2: 
      {
	cout << "Enter the student id: ";
	cin >> u_id;
	do 
	  {
	    s_menu = showStuMenu();
	    
	    switch (s_menu)
	      {
	      case 1:
		{
		  addCourse(ar[id_check]);
		  break;
		}
	      case 2:
		{
		  dropCourse(ar[id_check]);
		  break;
		}
	      case 3:
		{
		  makePayment(ar[id_check]);
		  break;
		}
	      case 4:
		{
		  showStuInfo(ar[id_check]);
		  break;
		}
	      case 5:
		{
		  
		  break;
		}
	      }
	  } while (s_menu != 5);
	
      }
      
      case 3:
	{
	  break;
	}
      }
  } while (m_menu != 3);
  
  return 0;
}

  //addStu(studentAR,count, curID); to add a student

  /***************************************************************
Test your program using the following test code. If your function names are different, change them.
  ***************************************************************/
  /*
  cout << "-------- adding the first student --------" << endl;
  addStu(studentAR,count,curID); //add first student
  cout << "-------- showing the first student --------" << endl;
  showStuInf(studentAR[0]);  //pass the first student 
  cout << "-------- adding student 2, 3, and 4 --------" << endl;
  addStu(studentAR,count,curID);//student ar is the array of students
  addStu(studentAR,count,curID);//count is used for the ammount of students
  addStu(studentAR,count,curID);//current ID will increment by 1
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(studentAR,count); //display all students by calling showStuInf
  cout << "-------- removing stu 2 --------" << endl;
  removeStu(studentAR,count); //remove the second stu
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(studentAR,count);//check
  cout << "-------- removing the last student --------" << endl;
  removeStu(studentAR,count); //remove the last stu                                                
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(studentAR,count);//check
  cout << "-------- adding from file --------" << endl;
  addStuFromFile(studentAR,count,curID); //from file fin
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(studentAR,count);//check
  
  cout << "-------- adding the first student --------" << endl;
  addStu(ar, count, id);
  cout << "-------- showing the first student --------" << endl;
  showStuInf(ar[0]);
  cout << "-------- addiing 111 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInf(ar[0]);
  cout << "-------- addiing 222 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInf(ar[0]);
  cout << "-------- addiing 222 again to a student ==> error --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInf(ar[0]);
  cout << "-------- removing 222 --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInf(ar[0]);
  cout << "-------- removing 333 ==> error --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInf(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 20 0. If you did, enter 20" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInf(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 10 14. If you did, enter 10.14" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInf(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "Did you work on the bonus feature where you reject an over payment? Enter Y or N:";
  char ans;
  cin >> ans;
  if(ans == 'Y' || ans == 'y')
    {
      cout << "-------- For bonus, making an overpayment ==> show error and won't be processed --------" << endl;
      makePayment(ar[0]);
      cout << "-------- showing the info --------" << endl;
      showStuInf(ar[0]);
    }
  else
    cout << "You didn't work on the bonus feather for overpayment" << endl;

  */

// ************************  PHASE 1  ****************************
/******************************
This function will add student into the array,
pass the array of students. count of students, and current id

student stuAr= student array
co=count
cid=current id
******************************/

void addStu(Student stuAR[],int& co, int& cID)
{
  string fn; //first name
  string ln; //last name
  char gn;//gender
  int id;//identification number
  
  //case 1 of admission
  cout << "\nEnter the first name: ";
  cin >> fn;

  cout << "Enter the last name: ";
  cin >> ln;
  
  cout << "Enter the gender: ";
  cin >> gn;
  
  id = cID;

  Student s( fn , ln , gn , id ); //student object created
  stuAR[co++] = s; //for first slot of array and next slot
  cID++; //increment the current id
}

/************************************

This function will show one of the student info by there id\

student s is just the object of one item in the array

student s is the object of student so one single piece of the array
*************************************/
                                                                                                                                             
void showStuInfo(const Student s)                                                                                       
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 
//look at testStuCollege input lab for example

  cout << "--------------------" << endl;                                                         
                                                                                                                                             
  cout << "first name: " << s.getFirstName()  << endl;                                                                                                 
 
  cout << "last name: " << s.getLastName()  << endl;                                                                                                  
 
  cout << "gender: " << s.getGender() << endl;                                                                                                      
 
  cout << "stu id: " << s.getStuID() << endl;                                                                                                      
 
  cout << "num classes: " << s.getNumClasses()  << endl;                                                                                                  
 
                                                                                                                                            
  cout << "Courses: ";                                                                                                                        
 
  for(int i = 0; i < s.getNumClasses() ; i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassOf(i)  << ", ";                                                                                                                 
 
                                                                                                                                              
  cout << "\nAmount owed $" << s.getBalance()  << endl;  //You have an operator overloading function to show a price object at once                   
 
  cout << endl;                                                                                                                               
 
  }

/**************************************************

This function will call showstuinf and display all of the students information
Pass over count so you know when to finish

stuAr is student array
co is count
************************************************/
void allStuInfo(Student stuAR[], int co)
{
  for (int i=0; i<co; i++)
    {
      showStuInfo(stuAR[i]);//call showStuInfo
    }
}

/*********************************************

Opperator overide function for == to check if student id from private function is == to id using find

returns true if found
returns false if not found
**********************************************/

bool operator==(const Student& s, int id) 
{
  if(s.getStuID()==id) //overload
    return true;
  else
    return false;
}

/********************************************

This function will ask for a student id and remove the student

use array.h and find function and remove function
********************************************/

void removeStu(Student stuAR[],int& co)

{
//Case 3 of Admission
  int id;   //used to search for id not in main
  cout<< "Enter the student id: ";//ask user for id
  cin>> id;
  int i=find(stuAR,co,id); //to display the student if found being removed
 
  //2 different messages

  if(i==-1)
    {
      cout << "Student with id " << id << " doesn't exist" << endl;
    }
  else
    {
      cout <<stuAR[i].getFirstName() << " " << stuAR[i].getLastName() << " has been removed." << endl;
      remove(stuAR,co,id);
      co--; //decrement count as u dont need to show another position of the array
    }

}

/**********************************************

This function will add student from a file

Use fin and inpput college.dat
**********************************************/

void addStuFromFile(Student stuAR[],int& co, int& cID)
{
  string fileName;

  cout << "Enter the file name: ";
  cin >> fileName; //file will need .dat since not added

  ifstream fin;
  fin.open(fileName.c_str()); //open the file

  if(!fin)//if not file is found
    {
      cout << fileName << " doesn't exist " << endl;
    }
  else//The file exists
    {
      string fn, ln;
      char gn;
      int id;
      fin >> fn >> ln >> gn;//read the first student
      while(fin)//if reading was successful, enter the while
	{
	  id=cID;
	  Student s( fn , ln , gn , id ); //student object created                                            
	  stuAR[co++] = s; //for first slot of array and next slot                                            
	  cID++; //increment the current id  
	  	  
	  fin >> fn >> ln >> gn; //read the next student
	}
    }
//Case 2 of admission
}



//*******************  PHASE 2 ****************************


void addCourse(Student& s)
{
//case 1 of student
//FYI, I am passing one student to this function not the array. 
  int crn;
  cout << "Enter a crn: ";
  cin >> crn;

  int add_crn= s.addCourse(crn);

//3 different messages to show

  // " has been added successfully" << endl;
  // " was not added because you have " << crn << " already." <<  endl;
  // " was not added because your schedule is full." <<  endl;
 
  if (add_crn == -1) //full
    cout << crn << " was not added because your schedule is already full." << endl;
  else if (add_crn == 0) //duplicate
    cout << crn << " was not added because you have " << crn << " already." << endl;
  else// (add_crn == 1)
    { //success
      cout << crn << " has been successfully added." << endl;
      s.addFee(50,14);
    }
}


void dropCourse(Student& s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array. 
  int crn;
  cout << "Enter a crn: ";
  cin >> crn;
  
  bool drop_crn= s.dropCourse(crn);

//2 different messages
    // " wasn't dropped from " << s.getFirstName() << " because " << cr << " doesn't exist" << endl;
    // " has been dropped successfully." << endl;
  if (drop_crn== false) //error
    cout << crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist." << endl;
  else if (drop_crn == true)
    {//success
      cout << crn << " has been dropped successfully." << endl;
      s.reduceFee(50,14);
    }

}


void makePayment(Student& s)
{
//case 3 of student
//FYI, I am passing one student to this function not the array.  
  int d_pay = 0, c_pay = 0;
  
  cout << "You owe " << s.getBalance() << endl; 
  cout << "Enter your payment: ";
  cin >> d_pay; //stores dollars
  cin.ignore(); //ignore 1 space
  cin >> c_pay; //stores cents

  if (c_pay > 99 || c_pay < 0 || d_pay < 0)
    {//if incorrect format
      cout << "The amount is in a wrong format." << endl;
    }
  else//if proper
    {
      s.reduceFee(d_pay, c_pay);
    }
}








//******************** PHASE 3 ****************************

bool checkPassword(int true_pass)
{
//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
  int correct_pass;
  cout << "Enter the password: ";
  cin >> correct_pass;
  if (true_pass == correct_pass)
    return true;
  else
    {
      cout << "The password is wrong." << endl << endl;
      return false;
    }

}



int findStu(Student s[], int n, int id)
{
//Small function. You may choose not to use this function. That is OK.

//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1

  int id_search;

  id_search = find(s, n, id);
  if (id_search == -1)
    {
      cout << "The student ID doesn't exist.";
      return -1;
    }
  else
    return id_search;
  
}


int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



