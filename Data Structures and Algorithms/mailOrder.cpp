/******

Reinier Swanepoel
3/26/2020
Mail Order

*****/

-------------------------------------------------------------------------------------------------------------------------------------

//Header filed Declaration

#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>

using namespace std;

//Global Varibale Declaration

float tax;

float discount;

int accNum, month, day, year;

char c_code;

string s;

//function prototype declaration

void getCustomerInfo(int accNum, int month, int day, int year, char c_code);

void getItemInfo(float price,int weight, int acc_num,int month, int day, int year, string s);

float price;
int weight;
int main()

{

  //text display

  cout<<setw(15)<<left<<"Month ordered"<<setw(15)<<left<<"Discount on total sale amount(before tax)"<<endl;
  cout<<setw(20)<<left<<"Jan-May"<<setw(20)<<left<<"5%"<<endl;
  cout<<setw(20)<<left<<"Jun-Aug"<<setw(20)<<left<<"10%"<<endl;
  cout<<setw(20)<<left<<"Sep-Dec"<<setw(20)<<left<<"15%"<<endl;

  cout<<endl;

  cout<<"Sales Tax:"<<endl;
  cout<<setw(20)<<left<<"San Diego Country"<<setw(20)<<left<<"7.75%"<<endl;
  cout<<setw(20)<<left<<"Orange Country"<<setw(20)<<left<<"7.75%"<<endl;
  cout<<setw(20)<<left<<"LA Country"<<setw(20)<<left<<"8.25%"<<endl;

  cout<<"Shipping:"<<endl;
  cout<<setw(20)<<left<<"25 pounds and under"<<setw(20)<<left<<"$5(flat rate)"<<endl;
  cout<<setw(20)<<left<<"26-50 pounds"<<setw(20)<<left<<"above rate for first 25 pounds and 10 cents for pounds over 25"<<endl;
  cout<<setw(20)<<left<<"over 50 pounds"<<setw(20)<<left<<"above rate for first 50 pounds and 7 cents/pound for pounds over 50"<<endl;

  cout<<endl;

  getCustomerInfo(acc_num, month, day, year, c_code);

  return 0;

}

void getCustomerInfo(int acc_num, int month, int day, int year, char c_code)

{

  //Asking for the user information

  cout<<"Enter Account Number: ";

  cin>>accNum;

  cout<<"Enter Date of Sale: ";

  cin>>month>>day>>year;

  cout<<"Enter country code: ";

  cin>>cCode;

  if(cCode == 'S')

    {

      s = "San Diego";

      tax = 0.0775;

    }

  if(c_code == 'O')

    {

      s = "Orange Country";

      tax = 0.0775;

    }

  if(c_code == 'L');

  {

    s = "LA";

    tax = 0.0825;

  }

  if(month>=1 && month <=5)

    {

      Discount = 0.05;

    }

  if(month>=6 && month <=8)

    {

      Discount = 0.10;

    }

  if(month>=9 && month <=12)

    {

      Discount = 0.15;

    }

  getItemInfo(price, weight, acc_num, month, day, year, s);

}

void getItemInfo(float price, int weight, int acc_num,int month, int day, int year, string s)

{

  float total_sale_amount = 0;

  int total_weight = 0;

  float shipping;

  char c;

do
  {

    cout<<"Do you want to order an item? Enter Y or N: ";

    cin>>c;

    if(c=='N')

      {

	break;

      }

    cout<<"Enter a price: ";

    cin>>price;

    cout<<"Enter a weight: ";

    cin>>weight;

    total_sale_amount = total_sale_amount + price;

    total_weight = total_weight + weight;

    cout<<endl;

  }while(c == 'Y');


 if(total_weight<25)

   {

     shipping = 5;

   }

 else if(total_weight >25 && total_weight < 50)

   {

     shipping = 5 + (total_weight - 25) * 0.1;

   }

 else if(total_weight >50)

   {

     shipping = 5 + (total_weight - 50) * 0.07;

   }

 float total_discount = total_sale_amount * Discount;

 float total_sales_tax = total_sale_amount * tax;

 float total_due = (total_sale_amount + total_sales_tax + shipping) - total_discount;

 cout<<setw(20)<<left<<"Account Number"<<setw(20)<<left<<"Country"<<endl;

 cout<<setw(20)<<left<<acc_num<<setw(20)<<left<<s<<endl;

 cout<<endl;

 cout<<"DATE OF SALE "<<month<<"/"<<day<<"/"<<year<<endl;

 cout<<endl;

 cout<<"TOTAL SALE AMOUNT: "<<"$ "<<total_sale_amount<<endl;
 cout<<"DISCOUNT:          "<<"$ "<<total_discount<<endl;
 cout<<"SALES TAX:         "<<"$ "<<total_sales_tax<<endl;
 cout<<"SHIPPING:          "<<"$ "<<shipping<<endl;
 cout<<"TOTAL DUE:         "<<"$ "<<total_due<<endl;

}

