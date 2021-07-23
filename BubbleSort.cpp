//Implement Bubble Sorting.
#include<bits/stdc++.h>
using namespace std;

void PrintArray(int arr[],int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void BubbleSort(int arr[],int n){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<(n-i-1);j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
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
	
	BubbleSort(arr,n);
	
	cout<<"After Sorting the Array: \n";
	PrintArray(arr,n);
	return 0;
}
