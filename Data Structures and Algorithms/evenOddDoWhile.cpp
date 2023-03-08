/*******
	
Reinier Swanepoel
2/28/2020
CS111

Even Odd Do While
 
Write a program that will read an unknown number of positive or negative numbers
from the keyboard and output “even” if the number is even or “odd” if it is odd. The user will enter a zero
when there are no more numbers to input. The program should display the total number of even numbers,
the total number of odd numbers and the average number in the end. If the user didn’t enter any positive
or negative numbers (she entered a zero for the first input), show “No numbers were checked”. 

*******/

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{ //make varibles = to 0
  int num; //number
  int totalOdd = 0; //total of Odd
  int totalEven = 0; //total of even
  int average; //to find the average number in the end
  int total=0; //total of numbers entered
  int count=0;  //ammount of numbers entered
  char answer; //answer y or n
  //part 2
  
  do
    {
      cout<< "Do you have a numbers to check? y or n: "; //ask user
      cin >> answer; //answer
    }while (answer != 'Y' && answer!= 'y' && answer!= 'N' && answer!= 'n');
  
  
  //check
  while(answer =='y' || answer =='Y')
    {
      
      cout << "Enter a number: ";
      cin >> num;
      
      //while(num>=0) //break out when the user enters a zero
      //{
      //To calculate the average number after the while loop, you need to do something here
      total=num+total; //=0
      count++; //make variables = to 0
      //check if the number is even or odd
      if(num%2==0 ||num==0) //make sure to equal to 0
	{
	  cout <<num<< " is even"<<endl; 
	  totalEven ++; //add 1 to even
	}
      else
	{
	  cout <<num<< " is odd"<<endl;
	  totalOdd ++; //add 1 to odd
	}
      cout <<endl;
      // }
      //input the next number
      do
	{
	  cout<< "Do you have a numbers to check? y or n: ";
	  cin >> answer;
	}while (answer != 'Y' && answer!= 'y' && answer!= 'N' && answer!= 'n');
      
      
    }
  cout<<endl;  
  //show the result
  if(totalOdd==0 && totalEven==0) //The user didn't check number for even or odd. She entered a zero for the first input.
    cout << "No numbers were checked" << endl;
  else //The user checked at least one number for even or odd. Then go ahead show the total numbers of even and odd and average number.
    {
      cout << totalEven << " even numbers" << endl; //even results
      cout<< totalOdd << " odd numbers" <<endl; //odd results
      cout <<fixed<<setprecision(2)<< "The average is " <<(double)total/count<<endl<<endl; //double of the int values
      //review fixed and setw and set precision
    }
  return 0;
}

