//Write a C++ program to check if a given string is a pangram
//Pangram Checking
//Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet.
//Examples : The quick brown fox jumps over the lazy dog ” is a Pangram [Contains all the characters from ‘a’ to ‘z’] 
//“The quick brown fox jumps over the dog” is not a Pangram [Doesn’t contain all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]
#include<bits/stdc++.h>
using namespace std;

bool pangram(string str){
	
	vector<bool> index(25,false);
	std::string::iterator it;
	
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
			return false;
		}
	}
	return true;
}
int main()
{
	string str;
	cout<<"Enter the String: ";
	getline(cin,str);
	
	if(pangram(str)==true){
		cout<<"The given string is a pangram\n";
	}
	else{
		cout<<"The given string is not a pangram\n";
	}
	return 0;
}
