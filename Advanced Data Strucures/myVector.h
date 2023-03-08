/*************************************************************

Reinier Swanepoel
CS211
Vector Lab

make a template vector class from scratch

***********************************************************/

#include <iostream>
using namespace std;

//prototypes
//void print(myVector<int> v);

template <class T>
class myVector
{

private:
  T* ar; //pointer to an array
  int num; //the number of elements in the array pointed to by ar

public:
  myVector();
  ~myVector();
  void push_back(const T& e);
  int size() const;
  T& operator[](int index);
  T operator[](int index) const; //  ???? operator[](int index) const;
  void erase(int index);
  void insert(int index,int e); //the new element, e, will sit at index
  
};

/***********************************************************

purpose: constructor using private

************************************************************/

template <class T> //above each function of this class, you need this.
myVector<T>::myVector() //use T even if you are not using T in this function.
{
  //initialize ar and num
  ar=NULL;
  num=0;

}

/**********************************************************

purpose: deconstructor


*********************************************************/
template <class T>
myVector<T>::~myVector() //destructor – we will talk more about it in the upcoming lectures
{//The destructor is called automatically when an object of the class goes out of scope
  //The destructor cannot be called by the programmer.
  //Don’t forget to delete the array in heap!
  if(ar != NULL)
    delete [] ar; //if ar points to an array, delete it

}

/*******************************************************

purpose: adds new element are the end

*******************************************************/

template <class T>
void myVector<T>::push_back(const T& e)//e could be big. Use pass by reference with const
{//try making it without size

  T* newAR = new T[num+1];
  
  for(int i=0; i<num; i++)
    {
      *(newAR+i) = *(ar+i); //copy values of old array of the vector to the new array
    }
     
  *(newAR+(num))=e; //adds a new element at the end

  num++; //increment num
  
  //adds a new element at the end
  // Reminder: Before you delete an array, you should make sure the pointer is not NULL.
  // If the pointer is NULL, it doesn’t point to an array.
  
  if( ar!= NULL)
    delete [] ar;
  
  //make ar point to the new array
  ar = newAR;

}

/****************************************************

purpose: will return the size

****************************************************/

template <class T>
int myVector<T>::size() const
{
  return num;
}

/***************************************************

purpose: overload so we can output a specific index

***************************************************/

template <class T>
T myVector<T>::operator[](int index) const
{
  return *(ar+index);
}


/****************************************


purpose: allows us to use replace elements in an index

******************************************/
template <class T>
T& myVector<T>::operator[](int index)
{
  if (index < num)
    return *(ar+index);
  else
    throw "invalid index";
}
/***********************************************

purpose: will delete the index and adjust the array

************************************************/
template <class T>
void myVector<T>::erase(int index)
{
  if(index >= num)
    {
      cout<<"illegal index" << endl;
    }

  else
    {
      
      for(int i=index; i<num; i++)
	{
	  ar[i] = ar[i+1]; //copy values of old array of the vector to the new array adjusted by 1 index                    
	}
      
      num--;
      // Reminder: Before you delete an array, you should make sure the pointer is not NULL.                                      
      // If the pointer is NULL, it doesn’t point to an array.                                                                    
      
    }
  
}


/***********************************************

purpose: will add at index x the number x

***********************************************/

template <class T>
void myVector<T>::insert(int index,int e)
{
  if(index >= num)
    {
      cout<<"illegal index" << endl;
    }

  else
    {
      num++;
      
      for (int i=num; i > index; i--)
	{
	  ar[i]=ar[i-1];
	}
      ar[index]=e;
    }

}



/**************************************************
main

testing functions; pushback size and operator
*************************************************/
/*
//prototypes
void print(const myVector<int>& vec);


int main()
{

  myVector<int> v; //You can use any data type
  //test your myVector functions.
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  //Calling push_back() multiple times

  // Call print() to show all the elements in the vector
  print(v); 

  v.erase(1);

  print(v);

  v.insert(1,0);

  print(v);

  cout << v.size() << endl;
  return 0;
}


void print(const myVector<int>& vec)
{

  for(int i = 0; i<vec.size() ; i++)
    {
      cout<<vec[i]<<" ";    
    }
  cout<<endl;
}
*/
