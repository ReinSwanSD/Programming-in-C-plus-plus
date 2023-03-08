/*********

Reinier Swanepoel
student.h

**********************************************************/
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;
#include "price.h"

const int MAX=6;

class Student 
{
  
 private:
  
  string first;
  string last;
  char gender;
  int numClasses;
  int classes[MAX];
  int stuID;
  Price balance;
  
  
 public:
  Student();
  Student(string fn, string ln, char gn,int id);
  int addCourse(int crn);
  void viewAllCourses()const;
  bool dropCourse(int crn);
  string getFirstName()const;
  string getLastName()const;
  char getGender()const;
  int getNumClasses() const;
  int getStuID()const;
  int getClassOf(int i)const;
  Price getBalance()const;
  void addFee(int d, int c);
  void reduceFee(int d, int c); 
  

  
  
};
#endif
