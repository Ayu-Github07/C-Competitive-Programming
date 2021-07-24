#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of terms in the Array: \n";
    cin>>n;

    int arr[n];
    cout<<"Enter the "<<n<<" numbers in the Array: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int len = sqrtl(n);
	    
    vector<int> b(len,0);
    
	for(int i=0;i<n;i++){
        b[i/len] += arr[i];
    }
    
    int q;
    cout<<"Enter the number of queries: \n";
    cin>>q;
    
    while(q--){
    	int l,r,sum=0;
    	cout<<"\nEnter the starting index: ";
    	cin>>l;
    	cout<<"Enter the ending index: ";
    	cin>>r;
    	
    	for(int i=l;i<=r;){
    		if(i%len == 0 && i+len <= r ){
    			sum += b[i/len];
    			i += len;
			}
			else{
				sum += arr[i];
				i++;
			}
		}
		cout<<"Sum in the Range: ["<<l<<" "<<r<<"] is: "<<sum<<endl;
	}
    return 0;
}
