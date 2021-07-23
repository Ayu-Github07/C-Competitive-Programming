//Implement Quick Sort
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

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void QuickSort(int arr[],int lb,int ub){
	int loc;
	
	if(lb<ub){
		loc = partition(arr,lb,ub);
		QuickSort(arr,lb,loc-1);
		QuickSort(arr,loc+1,ub);
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
	
	QuickSort(arr,0,n-1);
	
	cout<<"After Sorting the Array: \n";
	PrintArray(arr,n);
	return 0;
}
