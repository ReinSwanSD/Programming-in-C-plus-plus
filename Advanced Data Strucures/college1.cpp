
#include <iostream>
#include <fstream>
#include <istream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "array.h"
#include "student.h"
#include "checkInput.h"

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

//prototypes
int showMenu();
int showAdmMenu();
int showStuMenu();
void addStu(Student sA[], int& id, int& n); //add student to array
void showStuInfo(const Student s); //displays 1 student of choice
void allStuInfo(const Student sA[], const int n); //displays all students
void removeStu(Student sA[], int& n); //removes student of choice
void addStuFromFile(Student sA[], int& n, int& id); //adds student from file
void addCourse(Student& s); //adds course to student schedule
void dropCourse(Student& s); //removes course from student schedule
void makePayment(Student &s); //make payment towards students' fees
bool checkPassword(int real_pass); //checks user input password with real password
int findStu(Student s[], int n, int id); //checks if student id exists in array

int main(){
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating

  int main_menu; //menu option for the first menu
  int stu_menu; //menu option for the student menu
  int admin_menu; //menu option for the admin menu
  Student ar[SIZE];

  bool pass_check; //checkPassword() true/false output
  int user_id; //user input student id for login
  int user_pass; //matching password for studID
  int id_check; //findStu() true/false
  /****MAIN MENU****/
  do {
    main_menu = showMenu();
    switch (main_menu){
    case 1: {
      pass_check = checkPassword(123);
      if (pass_check == true){
        do {
	  admin_menu = showAdmMenu();
	  /****Admin Menu Option Results****/
	  switch (admin_menu){
          case 1:{ //add student
            addStu(ar, curID, count);
            break;
          }
          case 2:{ //add student from file
            addStuFromFile(ar, count, curID);
            break;
          }
          case 3:{ //drop a student
            removeStu(ar, count);
            break;
          }
          case 4:{ //display 1 student
            cout << "Enter the student id: ";
            cin >> user_id;
            id_check = findStu(ar, count, user_id);
            if (id_check != -1)
              showStuInfo(ar[id_check]);
            break;
          }
          case 5:{
            allStuInfo(ar, count);
            break;
          }
          case 6:{
            //nothing happens
            break;
          }
	  }} while (admin_menu != 6);
      }
      break;
    }
    case 2: {
      cout << "Enter the student id: ";
      cin >> user_id;
      id_check = findStu(ar, count, user_id);
      if (id_check != -1){
        user_pass = user_id % (PRIME1 * PRIME2);
        pass_check = checkPassword(user_pass);
        if (pass_check == true){
          cout << "Welcome " << ar[id_check].getFirstName() << endl;
          do {
	    stu_menu = showStuMenu();
	    /****Admin Menu Option Results****/
	    switch (stu_menu){
	    case 1:{
	      addCourse(ar[id_check]);
	      break;
	    }
	    case 2:{
	      dropCourse(ar[id_check]);
	      break;
	    }
	    case 3:{
	      makePayment(ar[id_check]);
	      break;
	    }
	    case 4:{
	      showStuInfo(ar[id_check]);
	      break;
	    }
	    case 5:{
	      //do nothing
	      break;
	    }
	    }} while (stu_menu != 5);
        }
      }
      break;
    }
    case 3: {
      break;
    }
    default: {
      cout << "Invalid response. Enter only 1-3: ";
    }
    }
  } while (main_menu != 3);

  return 0;
}

// ************************  PHASE 1  ****************************

/*****************************************************
addStu() lets user fill out the information for a student.

fN is the user input first name (string)
lN is the user input last name (string)
gen is the user input gender (char)
*****************************************************/
void addStu(Student sA[], int& id, int& n){
  //case 1 of admission
  cout << endl;
  //define user input
  string fN;
  string lN;
  char gen;
  
  //user input
  cout << "Student first name: ";
  cin >> fN;
  cout << "Student last name: ";
  cin >> lN;
  cout << "Student gender (m/f): ";
  cin >> gen;
  
  //create a Stu object
  Student s(fN, lN, gen, id);
  id++; //increase current id by 1 for next student

  //copy the info from the stu obj into the array at the appropriate slot
  sA[n] = s;
  n++; //increases amount of students
}

/******************************************************
showStuInfo() takes a student object as a paramter
and shows all of that student's data
*****************************************************/                                                               
void showStuInfo(const Student s){
  //*********************************************************************
  //DO NOT send the entire array to this function. BIG deduction if you do.
  //SEND only ONE student object as a parameter. If you don't know how, check
  //lab1-struct.cpp.
  //********************************************************************** 

  cout << "--------------------" << endl;                                                         
  cout << "first name: " <<  s.getFirstName() << endl;                                                                                                 
  cout << "last name: " << s.getLastName()  << endl;
  cout << "gender: " << s.getGender() << endl;                                                      
  cout << "stu id: " << s.getStuID() << endl;
  cout << "num classes: " << s.getNumClasses()  << endl;
  cout << "Courses: ";    
                                                                                                                    
  for(int i = 0; i < s.getNumClasses() ; i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?     
    cout << s.getClassOf(i)  << " ";

  cout << "\nAmount owed " << s.getBalance()  << endl;  //You have an operator overloading function to show a price object at once
  cout << endl;                                                                                                                           
}


void allStuInfo(const Student sA[], const int n) {
  if (n != 0){ //only if there are students
    //loop for every student
    for(int i = 0; i < n; i++){
      showStuInfo(sA[i]);
    }
  }  
  else {
    cout << "There are no students to display." << endl;
  }
}

/*******************************************
operator== overload

lets the program compare student IDs
*****************************************/

bool operator==(const Student& s, int id) {
  if (s.getStuID() == id)
    return true;
  else
    return false;
}

/*********************************************************
removeStu()

Finds the student in the Student array using
a user input ID and removes them from the array.

key_id (int) is the user input id used to search the array
rem_stu (Student) is used to temporarily store the information of the removed student
rem_stu_id (int) is the index of where the student to be removed in the array
**********************************************************/
void removeStu(Student sA[], int& n){
  int key_id; // id to search for
  Student rem_stu; //the student to be removed
  int rem_stu_i; //the index of the student to remove
  cout << "Enter the student id: ";
  cin >> key_id; //takes the user input for an ID

  rem_stu_i = find(sA, n, key_id);
  if (rem_stu_i == -1) { //if no student is found, error message
    cout << "Student with id " << key_id << " doesn't exist" << endl;
  }
  else {
    rem_stu = sA[rem_stu_i];
    remove(sA, n, key_id);
    //n--;
    cout << rem_stu.getFirstName() << " " << rem_stu.getLastName() << " has been removed." << endl;
  }
}

/******************************************
addStuFromFile() adds a student from a file 
of text. It continues to read from the text 
file until it reaches the end. The user must 
input the file name. An invalid file name
gives the user an error message.

filename (string) is the user input file name
fN (string) is the student's first name from the file
lN (string) is the student's last name from the file
gen (char) is the student's gender from the file
******************************************/
void addStuFromFile(Student sA[], int& n, int& id){
  //Case 2 of admission
  //define
  string fN, lN;
  char gen;

  string filename; //store user input filename
  cout << "Enter the file name: ";
  cin >> filename;

  //file
  ifstream input(filename.c_str());
  if (!input.is_open())
    cout << filename << " does not exist." << endl;
  else {
    while (!input.eof()) {
      input >> fN; //stores first name
      input.ignore(); //ignores space
      input >> lN; //stores last name
      input.ignore(); //ignores space
      input >> gen; //stores gender
      input.ignore();

      //create a Stu object
      Student s(fN, lN, gen, id);
      id++; //increase current id by 1 for next student

      //copy the info from the stu obj into the array at the appropriate slot
      sA[n] = s;
      n++; //increases amount of students
    }
  }
}

/*******  PHASE 2 *******/

/******************************************
addCourse() calleds Student::addCourse to add a course. Student::addCourse responds with an int

crn (int)is the user input course number
add_status (int) is the output from Student::addCourse. -1 means schedule full, 0 means class already exists in schedule, 1 means class successfully added.
******************************************/
void addCourse(Student& s){ //case 1 of student
  int crn;
  cout << "Enter a crn: ";
  cin >> crn;
  int add_status = s.addCourse(crn);
  if (add_status == -1) //full
    cout << crn << " was not added because your schedule is already full." << endl;
  else if (add_status == 0) //duplicate
    cout << crn << " was not added because you have " << crn << " already." << endl;
  else if (add_status == 1){ //success
    cout << crn << " has been successfully added." << endl;
    s.addFee(50,14);
  }
  else
    cout << "!!!error!!!" << endl; //should never show up
}

/******************************************
dropCourse() calleds Student::dropCourse to drop a course. Student::dropCourse responds with true/false after calling remove() from array.h

drop_status (bool) stores the response from Student::dropCourse
crn (int)is the user input course number
******************************************/
void dropCourse(Student &s){ //case 2 of student
  int crn;
  cout << "Enter a crn: ";
  cin >> crn;
  bool drop_status = s.dropCourse(crn);
  if (drop_status == false)
    cout << crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist." << endl;
  else if (drop_status == true){
    cout << crn << " has been dropped successfully." << endl;
    s.reduceFee(50,14);
  }
}

/******************************************
makePayment() calls getBalance to show how much a student owes,then asks how much the studetn would like to pay off.

d_pay (int) is the dollar amount the student wants to pay off
c_pay (int) is the cents amount the tudent wants to pay off
pay_over (int) checks to see if the student is trying to pay over the amount due
******************************************/
void makePayment(Student &s){
  int d_pay = 0, c_pay = 0;
  cout << "You owe " << s.getBalance() << endl; 
  cout << "Enter your payment: ";
  cin >> d_pay; //stores $$
  cin.ignore(); //ignore space or period
  cin >> c_pay; //stores c
  if (c_pay > 99 || c_pay < 0 || d_pay < 0){
    cout << "Invalid format." << endl;
  }
  else {
    Price payment(d_pay, c_pay); //creates price to compare
    if (payment > s.getBalance()){
      cout << "You owe " << s.getBalance() << " and you are trying to pay too much." << endl;
    }
    else{
      s.reduceFee(d_pay, c_pay);
    }
  }
}


/******************** PHASE 3 ****************************/

/***************************
checkPassword()
takes the real password (real_pass) and compares it to the user input

user input password is stored in user_pass and is compared to real_pass to determine if the password is correct (true/false)

admin password is 123
student password is student id % (PRIME1*PRIME2)
****************************/
bool checkPassword(int real_pass){
  int user_pass;
  cout << "Enter the password: ";
  cin >> user_pass;
  if (real_pass == user_pass)
    return true;
  else{
    cout << "The password is wrong." << endl << endl;
    return false;
  }
}

/***************************
findStu()
takes user input (id) and searches through student array to find it. The find() funtion returns -1 if student was not found.

s is the student array, n is the size of the array
****************************/
int findStu(Student s[], int n, int id){
  int id_match;

  id_match = find(s, n, id);
  if (id_match == -1){
    cout << "The student ID doesn't exist.";
    return -1;
  }
  else
    return id_match;


  //Small function. You may choose not to use this function. That is OK.

  //Ask for the student id
  //call find() to find the student id
  //return what find() returned which is index where it was found or -1
}

/*************************************
showMenu()

1 for admission office
2 for student
3 to end the program
***********************************/
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
/***********************************
showStuMenu()                                                                     

1 for add a course
2 for drop a course
3 to make a payment
4 to view information
5 to exit
***********************************/
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

/*******************************
showAdmMenu()

1 for add a student
2 for adding a student from file
3 to drop a student 
4 to view a student's info
5 to view all student info
6 to quit
*****************************/

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

