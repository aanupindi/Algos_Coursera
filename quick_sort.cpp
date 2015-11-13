#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdint.h>


int main(int argc, char **argv)
{
	if(argc  < 2)
	{
		std::cout<<"Please enter input array filename"<<std::endl;
		return 0;
	}
	quick_sort qs;

	std::string arrayFilename = argv[1];

	std::vector<int> a;
	qs.populateVector(arrayFilename,a);
	//partition(a,0,a.size()-1);
	qs.quicksort(a,0,a.size()-1);

	std::cout<<qs.getComparisons()<<std::endl;

	// for (int i = 0; i < a.size(); ++i)
	// {
	// 	std::cout<<a[i]<<std::endl;
	// }
	
}
