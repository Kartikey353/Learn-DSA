#include <bits/stdc++.h>
using namespace std;


int Linearsearch(int arr[], int n, int x)
{
  // iterating over array
	for (int i = 0; i < n; i++)
		if (arr[i] == x)  // if ele is found return the index of element.
			return i;       // else return -1 i.e, not found in this array.
	return -1;
}

// time complexity-> O(n)
//space complexity-> O(1)
int main()
{
  int size,ele;  //size is Size of array and ele is our target element.
  cin>>size>>ele
	int arr[size];  
  for(int i=0;i<size;i++){
      cin>>arr[i];}       // taking array inputs

	int index = search(arr, n, x);
	if (index == -1)
		cout << "Element is not present in the array";
	else
		cout << "Element found at position " << index;

	return 0;
}
