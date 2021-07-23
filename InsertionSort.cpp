//Implement Insertion Sort.
#include<bits/stdc++.h>
using namespace std;

void PrintArray(int arr[],int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void InsertionSort(int arr[],int n){
	
	int j,key;
	for(int i=1;i<n;i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && key<arr[j]){
			arr[j+1]  =arr[j];
			j -= 1;
		}
		arr[j+1] = key;
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements in an Array: \n";
	cin>>n;
	
	int arr[n];
	cout<<"Enter "<<n<<" numbers in the Array: \n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"Original Array: \n";
	PrintArray(arr,n);
	
	InsertionSort(arr,n);
	
	cout<<"After Sorting the Array: \n";
	PrintArray(arr,n);
	return 0;
}
