/*Find the first and last occurence of a particular element
** in a sorted array in ascending order. This uses Binary Search
** in a modified manner. This also helps in finding the range 
** in which the search element shows up multiple times in an array
**
*/
#include <iostream>
#include <vector>

int bSearchFirst(std::vector<int> a, int x, int n, int low, int high, int& first)
{
	if(a.size() == 0 || (low > high) )
		return -1;
	int mid = low + (high -low)/2;

	if( x == a[mid])
	{
		first = mid;
		high = mid -1;
	}
	else if( x < a[mid])
		high = mid - 1;
	else
	{
		low = mid + 1;
	}
	return bSearchFirst(a, x, n, low, high, first);
}

int bSearchLast(std::vector<int> a, int x, int n, int low, int high, int& last)
{
	if(a.size() == 0 || (low > high) )
		return -1;
	int mid = low + (high -low)/2;

	if( x == a[mid])
	{
		last = mid;
		low = mid + 1;
	}
	else if( x < a[mid])
		high = mid - 1;
	else
	{
		low = mid + 1;
	}
	return bSearchLast(a, x, n, low, high, last);
}

std::vector<int> searchRange(std::vector<int> a)
{
	int target1 = bSearchFirst(v, x, arrayLen, 0, arrayLen-1, first);
	int target2 = bSearchLast(v, x, arrayLen, 0, arrayLen-1, last);
	std::vector<int> v;
	v.push_back(first);
	v.push_back(last);
	return v;
}

int main(int argc, char const *argv[])
{
	int arrayLen;
	std::cout<<"Enter search array length"<<std::endl;
	std::cin >> arrayLen;
	//int *a = new int[arrayLen];
	std::vector<int> v;
	std::cout<<"Enter the search array elements"<<std::endl;
	int i = 0;
	while(i < arrayLen)
	{
		int element;
		std::cin >> element;
		v.push_back(element);
		i++;
	}
//	int a[10] = {10,20,34,34,34,71,85,86,87,88};
	//std::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	int first = -1, last = -1;
	std::cout<<"Enter the search element"<<std::endl;
	int x;
	std::cin >> x;
	
	//int target1 = bSearchFirst(v, x, arrayLen, 0, arrayLen-1, first);
	//int target2 = bSearchLast(v, x, arrayLen, 0, arrayLen-1, last);
	//std::cout<<"first occurence is "<<first<<"and the last occurence is"<<last<<std::endl;
	return 0;
}
