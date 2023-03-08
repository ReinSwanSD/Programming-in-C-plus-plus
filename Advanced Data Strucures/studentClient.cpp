/***********************************************************                                                             
                                                                                                                         
Reinier Swanepoel                                                                                                        
studentClient.cpp                                                                                                                
                                                                                                                         
**********************************************************/
#include <iostream>
using namespace std;
#include "student.h"

int main()
{

  Student stuA("Mike","Smith",'m');

  stuA.addCourse(100);
  cout<<stuA.addCourse(100)<<" has been added"<<endl;                                                    

  stuA.addCourse(200);
             

  stuA.viewAllCourses();
  cout<<endl;
  stuA.dropCourse(100);

  stuA.viewAllCourses();
  cout<<endl;








  return 0;

}
