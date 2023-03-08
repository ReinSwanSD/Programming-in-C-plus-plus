/*************************

Reinier Swanepoel
CS211
Kazumi Slott

constant and static and inheritance

*************************/

#include <iostream>
#include <string>
using namespace std;

//################################# Person Class ################################

class Person //base class
{
protected:
  static int num;
  static int start_id;
  const int ID;
  string fn;
  string ln;
  string SSN;
  string email;
  
public:
  Person(string f = "unknown", string l = "unknown", string ssn = "000-00-0000", string em = "unknown") :ID(start_id)
  {
    fn= f;
    ln= l;
    SSN= ssn;
    email= em;
    start_id++;
    num++;
  }
  void printInfo();
  static int getNum();
  static int getCurID();
};

//initialize static data member
int Person :: start_id = 1000;
int Person :: num = 0; 
 
//member functions

/* OLD WAY OF GETTING FUNCTIONS
string Person::getFirstName()
{
  return fn;
}

string Person::getLastName()
{
  return ln;
}

string Person::getSSN()
{
  return SSN;
}

string Person::getEmail()
{
  return email;
}
*/

void Person::printInfo()
{
  cout<< "Person::printInfo()" <<endl;
  cout<< ID << "(ID)" << fn << "(fn)" << ln << "(ln)" << SSN << "(SSN)" << email << "(email)" <<endl;
}
 //since in protected class, anyone can access
int Person:: getNum()
{
  return num;
}

int Person::getCurID()
{
  return start_id;
}

//############################### Factulty Class #############################

class Faculty : public Person // faculty is a inherited class of person class( base class)
{
private:
  int dept_id;
  int years;
  
public:
  Faculty(string f = "unknown", string l = "unknown", string ssn ="000-00-0000", string em = "unknown", int d_id = -1, int yrs = -1): Person(f, l, ssn, em) //inherited from person
  {
    dept_id = d_id;
    years = yrs;
    
  }  
  void printInfo();

  
  
};

void Faculty::printInfo()
{
  cout << "Faculty::showInfo()" << endl;
  Person::printInfo(); //Calling the function of the base class                                                               
  cout << dept_id  << "(Department ID)" << years << "(Years)"<< endl;
}

//################################ Student Class #############################3

class Student : public Person // student is a inherited class of person class
{
private:
  string major;
  double gpa;
  char grade;
  
  
public:
  Student(string f= "unknown", string l= "unknown", string ssn="000-00-0000", string em= "unknown", string m= "unknown", double g = -1.00, char gr = '?'): Person(f, l, ssn, em)
  {
    major = m;
    gpa = g;
    grade = gr;
  }  
  void printInfo();

  
  

};

void Student:: printInfo()
{
  cout << "Student::showInfo()" << endl;
  Person::printInfo(); //Calling the function of the base class
  cout << major << "(Major)" << gpa << "(GPA)" << grade << "(Grade)"<< endl;
}
//############################## Main Client ##################################

int main() 
{

  Student s1("Mike", "Smith", "111-222-3333", "mike@csusm.edu", "CS", 3.25, 'S');
  Faculty f1("Mike", "Smith", "111-222-3333", "mike@csusm.edu", 100, 5);
  Person p("unknown", "unknown", "000-00-0000", "unknown");
  Faculty f2("Kathy", "Ross", "222-33-4444", "kathy@csusm.edu", 100, 2);
  Student s2("Tom", "Lopez", "333-44-5555", "tom@csusm.edu", "CS", 3.33, 'J');

  cout<<"-------------test contructor for student ------------------"<<endl;
  s1.printInfo(); //1000
  cout<<"\n-----------test constructor for faculty--------------------"<<endl;
  f1.printInfo(); //1001
  cout<<"\n----------test default person class---------------------"<<endl;
  p.printInfo(); //1002
  cout<<"\n----------test object from faculty class---------------------"<<endl;
  f2.printInfo(); //1003
  cout<<"\n----------test object from student class---------------------"<<endl;
  s2.printInfo(); //1004
  cout<<"\n----------testing checks for num and id---------------------"<<endl;
  

  cout << "Checking value of num: total number of people is " << Person::getNum() << endl;
  cout << "Checking value of current ID: ID for the next person is " << Person::getCurID() << endl;

}
