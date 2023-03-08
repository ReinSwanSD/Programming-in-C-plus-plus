/****************************************************************************

Reinier Swanepoel
3/26/2020

Mail Order

Create an invoice for ABC Clothing Store on their charges with customers
ordering through their catalogue.

*****************************************************************************/

//Header Declaration

#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include "input.h"

using namespace std;

//Global Varibale Declaration
//p1 customer info
double tax; //tax percent for each county
double discount;//discount based on the time of year by month

int accNum; //account number 1000-9999
int month; //month 01-12
int day; //day 01-31
int year; //year as 2000-2100

char cCode; //county code 'S' for san diego 'O' for orange county 'L' for LA
string s;// full name of county
//p2 order info
double price; //price of the items the customer is ordering
double totalPr=0; //all prices added up
int weight; //weights of the items the customer is ordering
int totalWt=0; //all weight added up
char ans; //response to order an item Y or N
//p3 discount on season
double discountAmount;//amount to discount from total
//p4 sales tax on region
double salesTax; //ammount to add to total
//p4 shipping for weight
double shipCost; //ammount to add to total
//function prototype declaration

void getCustomerInfo(int & accNum, int & month, int & day, int & year, char & cCode);
void getItemsInfo(double price,double & totalPr, int weight,int & totalWt, char ans);

//pass by value
double calcDiscount(double totalPr,int month); //returns double discountAmount
double calcSalesTax(double discountAmount, double totalPr,char cCode); //return salesTax
double calcShipping(int totalWt,double shipCost,double totalPr); //return shipCost

//output invoice
void outputInvoice(int accNum,double saleTax, double shipCost); //correct output

//start
int main()
{

  getCustomerInfo(accNum, month, day, year, cCode); //important for parameters
  //  cout<< accNum << " " << month<< "/" <<day<<"/"<<year<<" "<<s<<endl;

  getItemsInfo(price,totalPr,weight,totalWt,ans); //use global
  //  cout<< totalPr << " " << totalWt<<endl;

  discountAmount=calcDiscount(totalPr,month); //calc doub
  //  cout<<discountAmount<<endl;

  salesTax=calcSalesTax(discountAmount, totalPr, cCode); //calc doub
  //  cout<< salesTax<<endl;

  shipCost= calcShipping(totalWt,shipCost,totalPr); //calc doub
  //  cout<<shipCost;

  outputInvoice(accNum,salesTax, shipCost); //output total
  // cout<<alllllll

  return 0;

}

/******

This function called getCustomerInfo that reads from the keyboard the account
number, the date of sale (month, day, and year as 3 integers), the county code
(‘S’ for San Diego County, ‘O’ for Orange County and ‘L’ for LA county).

*****/

void getCustomerInfo(int & accNum, int & month, int & day, int & year, char & cCode)
{
  //Asking for the user information
  
  cout<<"Enter an account number: ";
  accNum = getInt(1000,9999,"An account number must be 1000-9999. Enter Again: ");
  cout<<endl;//min 1000 max 9999 nothing else
  cout<<"Enter a month: ";
  month = getInt(1,12,"A month must be 1-12. Enter again: ");
  cout<<endl; //min 1 max 12 nothing else
  cout<<"Enter a day: ";
  day = getInt(1,31,"A day must be 1-31. Enter again: ");
  cout<<endl;//min 1 max 31
  cout<<"Enter a year: ";
  year = getInt(2000,2100,"A year must be 2000-2100. Enter again: ");
  cout<<endl; //min 2000 max 21000
  cout<<"Enter a country code. Enter S, O, or L: ";
  cin>>cCode;//S O L
  cout<<endl;

  while(cCode != 'S' && cCode != 'O' && cCode != 'L')
    {//only accept proper answers
      
      do
	{
	  cout<< "Invalid county code. Enter uppercase S,O, or L: ";
	  cin>>cCode;
	  cout<<endl;
	}while(cCode != 'S' && cCode != 'O' && cCode != 'L');
    }//dowhile notes
  //for string S to correlate with char cCode
  if(cCode == 'S')
    {
      s = "San Diego";
    }
  if(cCode == 'O')
    {
      s = "Orange County";
    }
  if(cCode == 'L')
    {
      s = "Los Angeles";
    }
}
/********
	 
This function called getItemsInfo that reads the prices and the weights 
(integer) of the items the customer is ordering. You don’t know how many items 
the customer is buying. In this function, you need to sum up the prices (total 
sale amount) and the weights (total weight). The total sale amount and total 
weight will be used to calculate a discount, the sales tax, and the shipping 
cost.

******/

void getItemsInfo(double price,double&totalPr, int weight,int&totalWt, char ans)
{//obtain price and weight, auto adds to total
  do
    { //how many items
      cout<< "Do you want to order an item? Enter Y or N: "; //ask user
      ans = getYN('Y', 'N', "Invalid response. Enter uppercase Y or N: "); //answer
      cout<<endl;
    }while(ans != 'Y' && ans != 'N');
  //do nothing if N
  while(ans =='Y')
    {
      //tab and ask
      cout << "\tEnter a price: ";
      price= getDouble(0.00,999.99,"A price must be between 0.00 and 999.99. Enter again: "); //min 0 max 999.99
      totalPr=price+totalPr;
      cout<<endl;//auto add
      //tab
      cout << "\tEnter a weight: ";
      weight= getInt(0,99,"A weight must be between 0 and 99. Enter again: ");
      totalWt=weight+totalWt; //auto add , min 0 max 99
      cout<<endl;

      do//more items?
	{
	  cout<< "Do you want to order an item? Enter Y or N: "; //ask user
	  ans = getYN('Y', 'N', "Invalid response. Enter uppercase Y or N: "); //an
	  cout<<endl;
	}while(ans != 'Y' && ans != 'N');
      
      }
}
/**********
	     
Write a function called calcDiscount that will calculate a discount amount. If
price is 100.00 and month is 5 (5% discount), this function should return 5.00.

******/

double calcDiscount(double totalPr,int month)
{
  if(month>=1 && month <=5) //if jan - may
    {
      discount = 0.05; //5%
    }
  
  if(month>=6 && month <=8) //june - august
    {
      discount = 0.10; //10%
    }
  if(month>=9 && month <=12) //september - december
    {
      discount = 0.15; //15%
    }
  
  discountAmount=totalPr * discount; //total disounted
  return discountAmount; //return amount
}
  
/**********
	     
Write a function called calcSalesTax that will calculate the sales tax (after discount is taken). If the county is S (7.75%), totalPrice is 100.00, and discount is 5.00, this function should return 7.3625 (7.75% of $95.00).

******/

double calcSalesTax(double discountAmount, double totalPr,char cCode)
{
  totalPr=totalPr-discountAmount; //new totalPr

  if(cCode == 'S')
    {
      //      s = "San Diego";
      tax = 0.0775;
    }

  if(cCode == 'O')
    {
      //      s = "Orange County";
      tax = 0.0775;
    }

  if(cCode == 'L')
    {
      //      s = "Los Angeles";
      tax = 0.0825;
    }

  salesTax=totalPr * tax;
  return salesTax; //return salesTax only 1 item updated

}

/********

This function called calcShipping that will calculate the shipping cost. If the
total weight is 26, this function should return 5.10.

*******/

double calcShipping(int totalWt,double shipCost,double totalPr)
{
  if (totalWt <= 25) //less that 25 pounds
    {
      shipCost=5.00;//flat rate
    }

  if (totalWt > 25 && totalWt <=50) //more than 25 less than 50
    {
      shipCost=5.00+(.10*(totalWt-25)); //flat rate plus extra weight
    }

  if (totalWt > 50) //more than 50
    {
      shipCost=7.50+(.07*(totalWt-50)); //flat rate plus 25 cost plus weight
    }

  return shipCost; //return ship cost
}

/**************

This function called outputInvoice that produces an invoice exactly as the sample output shown below:(image on document)

*********/

void outputInvoice(int accNum,double saleTax, double shipCost)
{
  cout<<endl;

  cout<<setw(30)<<left<<"ACCOUNT NUMBER"<<setw(20)<<left<<"COUNTY"<<endl;

  cout<<setw(30)<<left<<accNum<<setw(20)<<left<<s<<endl;

  cout<<endl;

  cout<<"DATE OF SALE:"<<month<<"/"<<day<<"/"<<year<<endl;

  cout<<endl;
  cout << fixed << setprecision(2);
  cout<<left<<setw(20)<<"TOTAL SALE AMOUNT:  "<<"$ "<<right<<setw(6)<<totalPr<<endl;
  cout<<left<<setw(20)<<"DISCOUNT:"<<"$ "<<right<<setw(6)<<discountAmount<<endl;
  cout<<left<<setw(20)<<"SALES TAX:"<<"$ "<<right<<setw(6)<<salesTax<<endl;
  cout<<left<<setw(20)<<"SHIPPING:"<<"$ "<<right<<setw(6)<<shipCost<<endl;
  cout<<left<<setw(20)<<"TOTAL DUE:"<<"$ "<<right<<setw(6)<<(totalPr-discountAmount+salesTax+shipCost)<<endl;
  cout<<endl;











}
