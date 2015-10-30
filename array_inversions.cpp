#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdint.h>

uint64_t merge(std::vector<int>& a, int mid, int low, int high)
{
	std::vector<int> sorted;
	int i , j;
	i = low;j = mid+1;
	uint64_t inv = 0;

	while(i <= mid && j <= high)
	{
		if(a[i] < a [j])
		{
			sorted.push_back(a[i]);
			i++;
		}
		else
		{
			sorted.push_back(a[j]);
			j++;
			for(int k = i;k<=mid;k++)
			{
				inv++;
			}
		}
	}

	while(i <= mid)
	{
		sorted.push_back(a[i]);
		i++;
	}
	while(j <= high)
	{
		sorted.push_back(a[j]);
		j++;
	}
	for(std::vector<int>::size_type i = 0; i < sorted.size(); i++) 
	{
     	a[i+low] = sorted[i];
	}
	sorted.clear();
	return  inv;
}

uint64_t mergeSort(std::vector<int>& a, int low, int high)
{
	uint64_t x,y,z;
	x=y=z=0;	
	if(low < high)
	{
		int mid = (high+low)/2;
		x = mergeSort(a,low,mid);
		y = mergeSort(a,mid+1,high);
		z = merge(a,mid,low,high);		
	}
	return (x+y+z);
}

void populateVector(std::string filename,std::vector<int>& inputVector)
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

int main(int argv, char** argc)
{
	if(argv  < 2)
	{
		std::cout<<"Please enter input array filename"<<std::endl;
		return 0;
	}
	std::string arrayFilename = argc[1];

	std::vector<int> a;
	populateVector(arrayFilename,a);

	uint64_t inv = mergeSort(a,0,a.size()-1);

	std::cout<<"number of inversions are "<<inv<<std::endl;
	std::cout<<"hello,world"<<std::endl;
	return 0;
}
