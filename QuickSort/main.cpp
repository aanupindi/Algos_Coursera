#include <iostream>
#include "quick_sort.h"

int main(int argc, char **argv)
{
	if(argc  < 3)
	{
		std::cout<<"Usage: ./quicksort <input_filename> <pivot_position>"<<std::endl;
		return 0;
	}
	if (argv[2] == "first")
	{
		quick_sort qs;
	}
	else
	{
		quick_sort_2 qs;
	}
	//quick_sort qs;

	std::string arrayFilename = argv[1];

	std::vector<int> a;
	qs.populateVector(arrayFilename,a);
	//partition(a,0,a.size()-1);
	qs.quicksort(a,0,a.size()-1);

	// for (int i = 0; i < a.size(); ++i)
	// {
	// 	std::cout<<a[i]<<std::endl;	
	// }
	std::cout<<"Output is "<<std::endl;
	qs.printArray(a);

	std::cout<<"Number of comparisons are "<<qs.getComparisons()<<std::endl;
	
}