#include <iostream>
#include <vector>

struct node {
int value;
struct node* left;
struct node* right;

struct node* CreateNode(int val, struct node* l, struct node* r)
{
    struct node* newNode = new node;
    newNode->value = val;
    newNode->left = l;
    newNode->right = r;
    return newNode;

};

struct node* CreateNode(int val, struct node* l, struct node* r)
{
    struct node* newNode = new node;
    newNode->value = val;
    newNode->left = l;
    newNode->right = r;
    return newNode;
}

struct node* createBTree(std::vector<int> a, int low, int high)
{
	if( a.size() == 0 || low > high)
		return NULL;
	int mid = low + (high -low)/2;
	node* root = CreateNode(a[mid], NULL,NULL);
    root->left = createBTree(a, low, mid - 1);
    root->right = createBTree(a, mid+1, high);
    return root;
	//return bSearchFirst(a, x, n, low, high, first);
}

int main(int argc, char const *argv[])
{
// 	int arrayLen;
// 	std::cout<<"Enter search array length"<<std::endl;
// 	std::cin >> arrayLen;
// 	//int *a = new int[arrayLen];
// 	std::vector<int> v;
// 	std::cout<<"Enter the search array elements"<<std::endl;
// 	int i = 0;
// 	while(i < arrayLen)
// 	{
// 		int element;
// 		std::cin >> element;
// 		v.push_back(element);
// 		i++;
// 	}
	int a[7] = {3,5,7,10,12,15,17};
    std::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
// 	int first = -1, last = -1;
// 	std::cout<<"Enter the search element"<<std::endl;
// 	int x;
// 	std::cin >> x;
	struct node* tr =  createBTree(v, 0, 6);
// 	//int target1 = bSearchFirst(v, x, arrayLen, 0, arrayLen-1, first);
// 	//int target2 = bSearchLast(v, x, arrayLen, 0, arrayLen-1, last);
// 	//std::cout<<"first occurence is "<<first<<"and the last occurence is"<<last<<std::endl;
	return 0;
}
