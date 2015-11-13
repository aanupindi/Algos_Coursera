/* Always choose the first element of the array as PIVOT*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdint.h>
#include "quick_sort.h"


quick_sort::quick_sort() 
{	
}

quick_sort::~quick_sort() {}

uint64_t quick_sort::comparisons=0;

void quick_sort::populateVector(std::string filename,std::vector<int>& inputVector)
{
	std::ifstream inputFile;
	std::string line;
	inputFile.open(filename.c_str());
	if(inputFile.is_open())
	{
		while(getline(inputFile,line))
		{
			std::stringstream ss(line);
			int value;
			ss >> value;
			inputVector.push_back(value);
		}
	}
	inputFile.close();
}

void quick_sort::printArray(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout<<v[i]<<std::endl;	
	}
}

void quick_sort::quicksort(std::vector<int> &a,int l, int r)
{
	if ((r - l) > 0)
	{
	int pivot = partition(a,l,r); // left and right separated.
	quicksort(a,l,pivot-1);
	quicksort(a,pivot+1,r);
	}
}

// Partition the array into left and right arrays.
int quick_sort::partition(std::vector<int> &a,int l, int r)
{
	int pivotValue = a[l];
	int pivot = l;
	int i = l+1;
	for(int j=l+1; j<=r;++j)
	{
		if (a[j] < pivotValue)
		{
			/* numbers need to rearranged. */
			if (i!=j)
			{
				swap(a,i,j);
			}
			++i;
		}
	}
	swap(a,pivot,i-1);
	setComparisons(r-l);
	return i-1;
}

void quick_sort::swap(std::vector<int> &a,int j, int i)
{
	int tmp;
	tmp=a[j];
	a[j]=a[i];
	a[i]=tmp;
}

uint64_t quick_sort::getComparisons()
{
	return comparisons;
}

void quick_sort::setComparisons(uint64_t c)
{
	comparisons +=c; 
}
