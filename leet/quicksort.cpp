#include < iostream>

//int main ( int argc, char* argv[])

void swap(int *addr1,int *addr2)
{
	int tmp = *addr1;
	*addr1 = *addr2;
	*addr2 = tmp;
}

// This returns the index of the partition 
// element in the current array
int partition( int arr[], int low, int high)
{
	int i, pivot, tmp;
	pivot = high;
	tmp = low;
	for( i = low; i<= high; ++i)
	{
		if(arr[i] < arr[pivot])
		{
			swap(&arr[i],&arr[tmp])
			++tmp;
		}
	}
	swap(&arr[tmp], &arr[pivot]);

	return pivot;
}

int quicksort(int arr[], int low, int high)
{
	while( low < high)
	{
		//int mid = low + ( high - low)>>2;
		int partition = partition(arr, low, high);
		quicksort(arr, low, partition-1);
		quicksort(arr, partition+1, high);
	}

}



int main ( int argc, char* argv[])
{
	std::cout<<"Enter the array size"<<std::endl;
	int arrLen;
	std::cin >> arrLen;
	int *arr = new int[arrLen];
	std::cout<<"Enter the array elements"<<std::endl;
	int i = 0;
	while(i < arrLen)
	{
		std::cin >> arr[i++];
	}
	quicksort(arr, 0, arrLen-1);
	i = 0;
	while( i < arrLen)
	{
		std::cout<<arr[i++]<<std::endl;
	}
	
		
