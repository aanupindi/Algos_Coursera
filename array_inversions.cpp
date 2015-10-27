#include <iostream>
#include <vector>

int merge(std::vector<int>& a, int mid, int low, int high)
{
	std::vector<int> sorted;
	int i , j;
	i = low;j = mid+1;
	int inv = 0;

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

int mergeSort(std::vector<int>& a, int low, int high)
{
	int x,y,z;
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
int main()
{
	
	//int myInts[] = {1,20,6,4,5};
	std::cout<<"Input length"<<std::endl;
	int arrayLen;
	std::cin>>arrayLen;
	std::cout<<"Input array"<<std::endl;
	std::vector<int> a;
	for (int i = 0; i < arrayLen; i++) {
    int b;
    std::cin >> b;
    a.push_back(b);
}

	//std::vector<int> a(myInts, myInts + sizeof(myInts) / sizeof(int));
	int inv = mergeSort(a,0,a.size()-1);
	for(std::vector<int>::size_type i = 0; i != a.size(); i++) 
	{
     	std::cout<< a[i]<<std::endl;
	}
	std::cout<<"number of inversions are "<<inv<<std::endl;
	std::cout<<"hello,world"<<std::endl;
	return 0;
}
