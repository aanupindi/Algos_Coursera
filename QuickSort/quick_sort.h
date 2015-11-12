#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

class quick_sort
{

private:
	static uint64_t comparisons;

public:
	quick_sort();
	~quick_sort();
	void populateVector(std::string filename,std::vector<int>& inputVector);
	void quicksort(std::vector<int> &a,int l, int r);
	int partition(std::vector<int> &a,int l, int r);
	void swap(std::vector<int> &a,int j, int i);
	uint64_t getComparisons();
	void setComparisons(uint64_t);
};