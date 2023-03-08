/*****************************************************                                                
Reinier Swanepoel                                                                                     
myStrCharFunc.h                                                                                               
CS211                                                                                                 
This header file provides useful operations on some utility functuins such as isLetter etc
                       
*****************************************************/
#ifndef MYSTRCHARFUNC_H
#define MYSTRCHARFUNC_H

#include <iostream>
using namespace std;

bool isLetter(char e);
char myToLower(char e);
char myToUpper(char e);


/*********************************                                                                   

isLetterDig() function                                                                               

Returns true if it is a letter                                                               
Returns false if not                                                                                 

*********************************/
bool isLetter(char e)
{
  //  if (e >= '0' && e <= '9') //digit                                                                   
  //  return true;

  if (e >= 'A' && e <= 'Z') //uppercase                                                          
    return true;
  
  else if (e >= 'a' && e <= 'z')
    return true;
  
  else
    return false;
}

/*********************************                                                                   

myToLower() function                                                                                  
for only caps letters                                                                                 
returns  letters and makes them lowercase.                                                                                                                                                        
*********************************/
char myToLower(char e)
{
  //  if (e >= '0' && e <= '9') //digit                                                                   
  //  return e;

  if (e >= 'a' && e <= 'z')
    return e;

  else// if (e >= 'A' && e <= 'Z') //uppercase                                                          
    return (e + 32);
}


/*********************************
myToUpper()
for only lowercase letters
returns uppercase letters
*********************************/
char myToUpper(char e)
{
  if (e >= 'a' && e <= 'z') //uppercase
    return (e - 32);
  else
    return e;
}

#endif
