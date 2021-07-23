//Implement Selection Sort
#include<bits/stdc++.h>
using namespace std;

void PrintArray(int arr[],int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void SelectionSort(int arr[],int n){
	
	for(int i=0;i<n;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
				min = j;
			}
		}
		swap(arr[i],arr[min]);
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
	
	SelectionSort(arr,n);
	
	cout<<"After Sorting the Array: \n";
	PrintArray(arr,n);
	return 0;
}
