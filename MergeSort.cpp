//Implement Merge Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

void PrintArray(int arr[],int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void Merge(int arr[],int lb,int mid,int ub){
	
	int i,j,k;
	int v[100];
	
	i = lb;
	j = mid+1;
	k = lb;	
	while(i<=mid && j<=ub){
		if(arr[i]<=arr[j]){
			v[k] = arr[i];
			i++;
		}
		else{
			v[k] = arr[j];
			j++;
		}
		k++;
	}
	while(j<=ub){
		v[k] = arr[j];
		j++; 
		k++;
	}
	
	while(i<=mid){
		v[k] = arr[i];
		i++; 
		k++;
	}
	
	for(int i=lb;i<=ub;i++){
		arr[i] = v[i];
	}
}
void MergeSort(int arr[],int lb,int ub){
	int mid = (lb+ub)/2;
	
	if(lb<ub){
		MergeSort(arr,lb,mid);
		MergeSort(arr,mid+1,ub);
		Merge(arr,lb,mid,ub);
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
	
	MergeSort(arr,0,n-1);
	
	cout<<"After Sorting the Array: \n";
	PrintArray(arr,n);
	return 0;
}
