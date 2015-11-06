#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdint.h>

void populateVector(std::string filename,std::vector<int>& inputVector);
int partition(std::vector<int> &a,int l, int r);
void quicksort(std::vector<int> &a,int l, int r);
void swap(std::vector<int> &a,int j, int i);

int main(int argc, char **argv)
{
	if(argc  < 2)
	{
		std::cout<<"Please enter input array filename"<<std::endl;
		return 0;
	}
	std::string arrayFilename = argv[1];

	std::vector<int> a;
	populateVector(arrayFilename,a);

	//partition(a,0,a.size()-1);
	quicksort(a,0,a.size()-1);

	for (int i = 0; i < a.size(); ++i)
	{
		std::cout<<a[i]<<std::endl;
	}
	
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

void quicksort(std::vector<int> &a,int l, int r)
{
	if ((r - l) > 0)
	{
	int pivot = partition(a,l,r); // left and right separated.
	quicksort(a,l,pivot);
	quicksort(a,pivot+1,r);
	}
}

// Partition the array into left and right arrays.
int partition(std::vector<int> &a,int l, int r)
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
	return i-1;
}

void swap(std::vector<int> &a,int j, int i)
{
	int tmp;
	tmp=a[j];
	a[j]=a[i];
	a[i]=tmp;
}