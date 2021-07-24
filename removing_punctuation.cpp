//Write a C++ program to remove punctuation from the string.
//Given a string, remove the punctuation from the string if the given character is a punctuation character as classified by the current C locale. The default C locale classifies these characters as punctuation: 
//
//!"#$%&'()*+,-./:;?@[\]^_`{|}~ 
//Examples: 
// 
//
//Input : %welcome' to @geeksforgeek<s
//Output : welcome to geeksforgeeks
//
//Input : Hello!!!, he said ---and went.
//Output : Hello he said and went
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cout<<"Enter the String: ";
	getline(cin,str);
	cout<<"Original String is: \n";
	cout<<str<<endl;
	
	for(int i=0,len=str.size();i<len;i++){
		if(ispunct(str[i]))
		{
			str.erase(i--,1);
			len = str.size();
		}
	}
	
	cout<<"\nAfter Removing Punctuation string is: \n";
	cout<<str<<endl;
	return 0;
}
