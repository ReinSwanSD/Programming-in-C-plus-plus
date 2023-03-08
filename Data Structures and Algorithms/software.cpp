/**************

Reinier Swanepoel
CS111
Software
2/19/2020

Write a program that asks for today’s date (you MUST use cin >> date. Do not use getline(cin, date)), the
company name and the quantity they wish to buy and computes the total cost of the purchase. If the user enters a
negative value for the quantity, tell him/her “invalid quantity”. If a zero is entered, tell “Hope you decide to buy
our software in the future.” Otherwise display an invoice in the same format shown below. 

******/

#include <iostream>
#include <iomanip> //dont know if this is needed
using namespace std;

int main()
{//code starts

  //variables

  string date;//(mm/dd/yy) of today
  string company; //company's name
  int quantity; //ammount you would like to purchase
  int iquantity;//variable equal to quanitity for if
  double iprice;//99 per unit
  double price; //iprice * quanitity
  double idiscount;// percentage off
  double discount;//dollar ammount off
  double total;//ammount after discount

  cout << "Enter today's date (mm/dd/yy): " ; //given information needed
  cin >> date; //must use cin

  cin.ignore(); 
  cout << "Enter your company name: ";
  getline(cin,company); //must enter a string or multiple words

  cout << "Enter the quantity you would like to purchase: ";
  cin >> quantity; //negative, 0 , and 1-100
  cout << endl;

  iquantity=quantity; //to help ifs
  iprice=99.00; //price per unit

  if (quantity>0) //making sure its a number larger than 0
    {   
    //receipt script falls in here

      cout << setw(30); //title
      cout <<"Invoice for Little Coffee Shop"<< endl<<endl;

    if (iquantity<10) //10 or less
       //no discount
       {
	 //        price=iprice*quantity; //total
        idiscount=0; //different than the rest. 
	//        total=price; //dont want 0 value
       }       
    else if (iquantity>=10 && iquantity<20) //10-19
       {
        idiscount=20; //discount percent
	//option1
	//	price=iprice*quantity; //how many and how much 
	//	idiscount=idiscount/100; //discount to be applied
	//	discount=price*idiscount; //discount total
	//	total=price-discount;//after discount
       }
    else if (iquantity>=20 && iquantity<50)//20-49
       {
	idiscount=30; //discount percent
	//copy the above script for each or keep at bottom
       }
    else if (iquantity>=50 && iquantity<100) //50-99
       {
	idiscount=40;
	//        price=iprice*quantity; option 2 is a cleaner way
       }
    else //100 or more
       {
        idiscount=50; //half off
       }
    //option2
     price=quantity*iprice; 
     discount=price*(idiscount/100);
     total=price-discount;

  cout << fixed << setprecision(2);
  cout << left << setw(30)<<"Price before discount"<<left<<"$"<<right<<setw(10)<<price<<endl; //double check by counting spaces
  cout << left << setw(30)<<"Discount"<<"$"<<right<<setw(10)<<discount<<endl; //dont always need to do left before $
  cout << left << setw(30)<<"Total Due"<<"$"<<right<<setw(10)<<total<<endl; //already in the system side, to change type left
  cout << endl;
    } 
  else if (quantity==0)//equal to 0
      
    cout << "Hope you decide to buy our software in the future. "<< endl<<endl; //please buy some
    
  else//less than 0
    cout << "Invalid quantity"<<endl<<endl; //why u buy negative item, no returns allowed
     

  return 0;
}
//end program
