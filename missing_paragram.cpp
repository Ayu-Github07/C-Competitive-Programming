//Write a C++ program Missing characters to make a string Pangram
//Pangram is a sentence containing every letter in the English alphabet. Given a string, find all characters that are missing from the string, i.e., the characters that can make the string a Pangram. We need to print output in alphabetic order.
//
//Examples: 
//
//Input : welcome to geeksforgeeks
//Output : abdhijnpquvxyz
//
//Input : The quick brown fox jumps
//Output : adglvyz
#include<bits/stdc++.h>
using namespace std;

string pangram(string str){
	
	vector<bool> index(25,false);
	std::string::iterator it;
	
	string missing;
	
	int i;
	for(it=str.begin();it<=str.end();it++){
		if(*it>='A'&&*it<='Z'){
			i = *it - 'A';
		}
		else if(*it>='a' && *it<='z'){
			i = *it - 'a';
		}
		else{
			continue;
		}
		index[i] = true;
	}
	for(int i=0;i<=25;i++){
		if(index[i]==false){
			missing.push_back((char)(i+'a'));
		}
	}
	return missing;
}
int main()
{
	string str,miss;
	cout<<"Enter the String: ";
	getline(cin,str);
	cout<<"Original String is: \n";
	cout<<str<<endl;
	
	miss = 	pangram(str);
	cout<<"Missing characters are: \n";
	cout<<miss<<endl;
	return 0;
}
