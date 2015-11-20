#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Array.h"
#include"settingNegative.h"
#include"HugeInteger.h"
using namespace std;
template<typename T>
void output(T x[], string j,int tsize)
{
	//output integers 3
	cout<<j<<endl;
		for (int i = 0;i<tsize ;i++)
	{
		if(i<4)
		cout<<setw(4)<<x[i];
		
		else
		{
			
			cout<<setw(4)<<x[i];
			
		}
		if(i == 3||i ==7)
		{cout<<endl;}
	
	}
};
void endls()
{
	cout<<endl<<endl;
};
int main()
{
	cout<<"create two arrays, integers1 - 7 elements, integers2 - default size";endls();
	Array<int>integers1(7);
	cout<<"size of array integers 1 is  "<<integers1.Size;endls();
	cout<<"array after intialization";endls();
	output(integers1.ptr,"integers1",integers1.Size);endls();
	Array<int>integers2;
	cout<<"size of array integers 2 is  "<<integers2.Size;endls();
	cout<<"array after intialization";endls();
	output(integers2.ptr,"integers2",integers2.Size);endls();
	ifstream inputFile;
	string filename;
	int number;
	inputFile.open("TopicGin.txt");
	if(inputFile)
	{
		int i = 0; 
		int j = 0;
		while(inputFile>>number)
		{
			if(i>=7)
			{
			integers2.ptr[j] = number;
			j++;
			}
			
			else if (i<7||i>17)
			{
			
			//cout<<number;
			integers1.ptr[i] = number;
			i++;
			}
			
		}
		inputFile.close();
	}
	else
	{
		cout<<"error opening file";
	}

	output(integers1.ptr,"integers1",integers1.Size);
	endls();
	output(integers2.ptr,"integers2",integers2.Size);
	endls();
	cout<<"Evaluating: integers 1 != integers2";endls();
	if(integers1!=integers2)
		cout<<"they are not equal";
	else
		cout<<"they are equal";
	endls();


	cout<<endl<<"Creating and assigning integers 3 to integers 1 "<<endl;
	endls();
	Array<int> integers3(7);
	integers3 = integers1;
	cout<<"Size of integers3 is "<<integers3.Size<<endl;
	output(integers3.ptr,"integers3",integers3.Size);
	endls();
	cout<<"Assigning integers2 to integers1 (integers1 = integers2): ";endls();
	integers1 = integers2;
	output(integers1.ptr,"integers1",integers1.Size);endls();
	output(integers2.ptr,"integers2",integers2.Size);endls();
		cout<<"evaluating if integers1 == integers2";endls();
		if(integers1 == integers2)
			{cout<<"they are equal";endls();}
		else
			cout<<"they are not equal";endls();

		/*cout<<"evaluating if integers 3 == integers 1"<<endl;
		if(integers1 == integers3)
			{cout<<"they are equal";endls();}
		else
			{cout<<"they are not equal";endls();}*/
		endls();
		cout<<"integers1[5]: is ";
		cout<<integers1[5];endls();
		cout<<"Assigning 1000 to integers1[5]";endls();
		integers1[5] = 1000;
		/*cout<<endl<<"setting integers1[3] to 100";endls();
		integers1[3] = 100;*/
		//cout<<"After input the arrays contain"<<endl<<"integers1:"<<endl;
	output(integers1.ptr,"integers1",integers1.Size);endls();
	cout<<"attempt to make an array with -7 length ";endls();
	Array<int>x(-7);endls();
	cout<<"attempt to reach integers1[29]";endls();
	integers1[29];endls();
	//making double array
	Array<double>doubleArray;
	//outputting double array
	cout<<"creating double array with default size ";endls();
	cout<<"reading 10 info from topicgin.txt";endls();
	inputFile.open("TopicGin.txt");
	if(inputFile)
	{	double number;
		int i = 0; 
		int j = 0;
		while(inputFile>>number)
		{
			if(i>=17&&i<28)
			{
			doubleArray.ptr[j] = number;
			j++;
			}
			else if(i>28)
				break;
			i++;
			
		}
		inputFile.close();
	}
	else
	{
		cout<<"error opening file";
	}
	output(doubleArray.ptr,"doubleArray",doubleArray.Size);endls();
	cout<<"setting first two elements to 2.7 and 3.4";endls();
	doubleArray[0] = 2.7;
	doubleArray[1] = 3.4;
	output(doubleArray.ptr,"doubleArray",doubleArray.Size);endls();
	cout<<"creating a string array of length 5";endls();
	Array<string>stringArray(5.0);
	cout<<"reading 5 words from file topicGin.txt: ";endls();
	inputFile.open("TopicGin.txt");
	if(inputFile)
	{	string number;
		int i = 0; 
		int j = 0;
		while(inputFile>>number)
		{
			if(i>=27&&i<32)
			{
			stringArray.ptr[j] = number;
			j++;
			}
			else if(i>32)
				break;
			i++;
			
		}
		inputFile.close();
	}
	else
	{
		cout<<"error opening file";
	}
	output(stringArray.ptr,"Display stringArray ",stringArray.Size);endls();
	cout<<"attempt to make an array with size 0";endls();
	Array<int>j(0);endls();
	cout<<"Creating a HugeInteger array of size 6";endls();
	Array<HugeInteger>hArray(6,0);endls();
	cout<<"display HugeInteger Array";endls();
	output(hArray.ptr,"hugInteger",hArray.Size);endls();
	cout<<"read input from the file";endls();
	inputFile.open("TopicGin.txt");
	if(inputFile)
	{	string number;
		int i = 0; 
		int j = 0;
		while(inputFile>>number)
		{
			if(i>31)
			{
			hArray.ptr[j].numberInput(number);
			j++;
			}
			else if(i>40)
				break;
			i++;
			
		}
		inputFile.close();
	}
	output(hArray.ptr,"hugeInteger",hArray.Size);endls();
	cout<<"Add first and second elements and assign the answer to third element";endls();
	hArray.ptr[2] = hArray.ptr[0]+hArray.ptr[1];
	output(hArray.ptr,"hugeInteger",hArray.Size);endls();
	cout<<"subtract first element from the second element and store in the fifth element";endls();
	hArray.ptr[4] = hArray.ptr[1] - hArray.ptr[0];
	output(hArray.ptr,"hugeInteger",hArray.Size);endls();
	cout<<"attempt to create an illegal HugeInteger Object: ";
	Array<HugeInteger>h(-2,0);
	endls();
	cout<<"attempt to have a negative result in subtraction";endls();
	hArray.ptr[2] = hArray.ptr[0] - hArray.ptr[4];
	
	endls();
	cout<<"Press enter to end -->";
	
	cin.ignore();
	return 0;
}

//class Array{
//	
//	
//public:
//	T * ptr;
//	int Size;
//	Array()
//	{
//		Size = 10;
//		ptr = new T[Size];
//		for(int i = 0;i <Size; i++)
//		ptr[i] = 0;
//	}
//Array ( int size)//constructor
//	{
//	Size = size;	
//		ptr = new T[size];
//	for(int i = 0;i <size; i++)
//		ptr[i] = 0;
//	}
//const Array &Array::operator=(const Array&right)
//{
//	if(&right != this)
//	{
//		if(Size!= right.Size)
//		{
//		delete []ptr;
//		Size = right.Size;
//		ptr = new int [Size];
//		}
//		for(int i = 0; i < Size; ++i)
//			ptr[i] = right.ptr[i];//copy array into object
//	}
//	return*this;
//}
//bool Array::operator==(const Array &right) const
//{
//	if(Size!=right.Size)
//		return false;
//	for(int i = 0; i < Size; i++)
//		if(ptr[i] != right.ptr[i])
//			return false;
//
//	return true;
//}
//T &Array::operator[](int subscript)
//{
//	if(subscript<0||subscript>=Size)
//		cout<<"subscript out of range";
//	return ptr[subscript];
//}
//};
////output integers 3
	//cout<<"integers 3: "<<endl;
	//	for (int i = 0;i<integers3.Size;i++)
	//{
	//	if(i<4)
	//	cout<<setw(4)<<integers3.ptr[i];
	//	
	//	else
	//	{
	//		
	//		cout<<setw(4)<<integers3.ptr[i];
	//		
	//	}
	//	if(i == 3||i ==7)
	//	{cout<<endl;}
	//
	//}
	////output integers 2 array
	//
	//cout<<endl<<"integers2:"<<endl;
	//for (int i = 0;i<integers2.Size;i++)
	//{
	//	if(i<4)
	//	cout<<setw(4)<<integers2.ptr[i];
	//	
	//	else
	//	{
	//		
	//		cout<<setw(4)<<integers2.ptr[i];
	//		
	//	}
	//	if(i == 3||i ==7)
	//	{cout<<endl;}
	//
	//}
	////output integers 1 array
	//cout<<"After input the arrays contain"<<endl<<"integers1:"<<endl;
	//for (int i = 0;i<integers1.Size;i++)
	//{
	//	cout<<setw(4)<<integers1.ptr[i];
	//	if(i == 3)
	//	{
	//		cout<<endl;
	//	}

	//}