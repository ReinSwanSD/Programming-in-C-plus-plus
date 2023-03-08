#include <iostream>

#include <iomanip>

using namespace std;

const int SIZE_TEACH=3;

int SIZE_STU;

void fillArray (int a[], string names[],int s);

int main()

{

  int a[SIZE_TEACH][SIZE_STU];

  string names[]={"Smith", "Ross", "Lopez"};

  int stu[s];

  fillArray(a, names, s);

  return 0;}

void fillArray (int a[], string names[], int s)

{

  for(int i=0; i<SIZE_TEACH;i++)

    {

      cout<<"Enter the number of students in " << names[i] <<" class: "<<endl;

      cin>>s;

      cout<<endl;

    }
