#include <iostream>
#include <vector>

using namespace std;

bool fiboSearch(const vector<int> &a, int key, int low, int high, vector<int>& result){
	
	int curr = key;
	while(curr){
		low = 0;
		high = a.size()-1;
		while(low <= high){
			int mid = ((unsigned int) low + (unsigned int)high) >> 1;
			if ( curr == a[mid]){
				result.push_back(a[mid]);
				return true;
			}	
			if( curr < a[mid])
				high = mid-1;
			else if( curr > a[mid]){
				if(curr < a[mid+1]){
					result.push_back(a[mid]);
					curr-=a[mid];
					break;	
					}
				low = mid+1;
			}
		}
	}
	return false;

}


int main(int argc, char** argv){


	int fiboArray[] = {0,1,1,2,3,5,8,13,21,34,55,89,144};
	vector<int> v(fiboArray,fiboArray+sizeof(fiboArray)/sizeof(fiboArray[0]));
	cout << "enter search element less than 100" <<endl;
	int searchElement;
	if(argc < 2){
		cout<<"enter the search element " <<endl;
		exit(0);
	}

	searchElement = stoi(argv[1]);

	vector<int> result;

	bool fiboComponent = fiboSearch(v,searchElement,0,v.size()-1,result);
	if(fiboComponent){
		for(auto& a : result)
		cout << a << std::endl;
	}
	return 0;
}


