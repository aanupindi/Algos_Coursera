#include<iostream>
//#define NDEBUG
#include<assert.h>

int main(int argc, char* argv[])
{	
	std::cout<<"Enter len of array"<<std::endl;
	int arrayLen = 0;
	std::cin >> arrayLen;
	assert(arrayLen);
	std::cout<<"Enter the array members"<<std::endl;
	int *a = new int [arrayLen];
	int i = 0;
	while ( i < arrayLen)
		std::cin >> a[i++];




	int *b = new int[arrayLen];
	int prod = 1;
	b[0] = prod;
	for(int i = 0;i < arrayLen-1; ++i)
	{
		b[i+1] = a[i] * prod;
		prod = b[i+1];
	}
	prod = a[arrayLen-1];
	for(int i = arrayLen-2; i >= 0; --i)
	{
		b[i]*= prod;
		prod*=a[i];	
	}
	std::cout<<"The products are "<<std::endl;
	for(int i = 0;i < arrayLen; ++i)
	{
		std::cout<<b[i]<<std::endl;
	}
	

}
	

