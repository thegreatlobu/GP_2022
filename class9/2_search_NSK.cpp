#include<iostream>
using namespace std;

#if 0
int* search(int* first, int* last, int key)
{
//	while(first <= last) // NO
//	while(first < last) // ok
	while(first != last) // prefer this
	{
		if(*first == key)
		{
			return first;
		}
		++first;
	}
	return first;
}
#endif

int* search(int* first, int* last, int key)
{
//	while(first <= last) // NO
//	while(first < last) // ok
	while(first != last && *first != key) // prefer this
	{
		++first; 
		// first = first + 1; // NO
	}
	return first;
}


int main(){
	int a[] = {1,2,3,4,5};
	int b[] = {5,6,7,8,9};
	int* res;
	res = search(a, a + 5, 4);
	if(res == a + 5)
	{
		cout << "not found\n";
	}
	else
	{
		cout << "found  : " << *res << "\n";
	}
	
	res = search(b, b + 5, 11);
	if(res == b + 5)
	{
		cout << "not found\n";
	}
	else
	{
		cout << "found  : " << *res << "\n";
	}	
	
	return 0;
}
