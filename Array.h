#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include"settingNegative.h"
#include"settingToohigh.h"
#include<string>
using namespace std;
template<typename T>
class Array
{
	
public:
	T * ptr;
	int Size;
	Array()
	{
		Size = 10;
		ptr = new T[Size];
		for(int i = 0;i <Size; i++)
		ptr[i] = 0;
	}
	Array ( double size)//constructor for string
	{
		try{
			if(size<1)
			{
				throw settingNegative();
			}
	Size = size;	
		ptr = new T[size];
	for(int i = 0;i <size; i++)
		ptr[i] = '0';
		

		}
		catch(settingNegative &x)
		{
			cout<<"exception occured"<<endl<<x.what();
			
		}
	}
	Array ( int size,int j)//constructor for hugeI
	{
		try{
			if(size<1)
			{
				throw settingNegative();
			}
	Size = size;	
		ptr = new T[size];
	for(int i = 0;i <size; i++)
		//ptr[i] = 00000;
		

;		}
		catch(settingNegative &x)
		{
			cout<<"exception occured"<<endl<<x.what();
			
		}
	}
Array ( int size)//constructor for ints and doubles
	{
		try{
			if(size<1)
			{
				throw settingNegative();
			}
	Size = size;	
		ptr = new T[size];
	for(int i = 0;i <size; i++)
		ptr[i] = 0;
		

		}
		catch(settingNegative &x)
		{
			cout<<"exception occured"<<endl<<x.what();
			
		}
	}
const Array &Array::operator=(const Array&right)
{
	if(&right != this)
	{
		if(Size!= right.Size)
		{
		delete []ptr;
		Size = right.Size;
		ptr = new int [Size];
		}
		for(int i = 0; i < Size; ++i)
			ptr[i] = right.ptr[i];//copy array into object
	}
	return*this;
}
bool Array::operator==(const Array &right) const
{
	if(Size!=right.Size)
		return false;
	for(int i = 0; i < Size; i++)
		if(ptr[i] != right.ptr[i])
			return false;

	return true;
}
bool Array::operator!=(const Array &right)const
{
return !(*this == right);		
}
T &Array::operator[](int subscript)
{
	try{
	if(subscript<0||subscript>=Size)
		throw(settingToohigh());
	return ptr[subscript];
	}
	catch(settingToohigh &x)
	{
		cout<<"exception occured "<<x.what();
	}
}
};
#endif