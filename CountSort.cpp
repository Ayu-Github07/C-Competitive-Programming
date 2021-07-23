//Implement Count Sort
#include<bits/stdc++.h>
using namespace std;

void PrintArray(int arr[],int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int maximum(int arr[],int n){
	int mx = INT_MIN;
	
	for(int i=0;i<n;i++){
		mx = max(mx,arr[i]);
	}
	return mx;
}
void CountSort(int arr[],int n){
	
	int m = maximum(arr,n);
	
	vector<int> v(m,0);
	
	for(int i=0;i<n;i++){
		int a = arr[i];
		v[a] += 1;
	}
	
	int j = 0;
	for(int i=0;i<=m;i++){
		if(v[i]!=0){
			int temp = v[i];
			while(temp--){
				arr[j] = i;
				j++;		
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
	
	CountSort(arr,n);
	
	cout<<"After Sorting the Array: \n";
	PrintArray(arr,n);
	return 0;
}
