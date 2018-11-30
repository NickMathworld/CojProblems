#include <bits/stdc++.h>
#define MAXN 52
using namespace std;
string reverseSubstring(string str,int i, int j ){
	string first  = str.substr(0,i);
	string second = str.substr(i,j);
	string third  = str.substr(j,str.size());
	cout << str << endl;
	cout << first << second << third << " " << i <<" "<< j << endl;
	reverse(first.begin(), first.end()); 
	reverse(second.begin(), second.end()); 
	reverse(third.begin(), third.end()); 
	return first+second+third;
}
string MaxSubstring(string str){
	string ans = "";
	for(int i=0;i<MAXN;i++)ans+="z";
	for(int i=1;i<str.size();i++)
		for(int j=i+1;j<str.size();j++)
			ans = min(ans,reverseSubstring(str,i,j));
	return ans;
}
int main(){
	string input = "";
	while(cin >> input)
		cout << MaxSubstring(input);
}