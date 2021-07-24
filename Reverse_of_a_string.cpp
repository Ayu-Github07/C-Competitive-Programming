//Write a C++ program to reverse the string letter by letter in
//a word.
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cout<<"Enter the string: ";
	getline(cin,str);
	
	std::string::iterator it;
	std::string::reverse_iterator rit;
	
	cout<<"Original String: \n";
	for(it = str.begin();it<=str.end();it++){
		cout<<*it;
	}
	cout<<"\n\n";
	
	cout<<"Reverse of a String: \n";
	for(rit = str.rbegin();rit<=str.rend();rit++){
		cout<<*rit;
	}
	cout<<endl;
	
	return 0;
}
