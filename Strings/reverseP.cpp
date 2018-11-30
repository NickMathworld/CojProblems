#include <bits/stdc++.h>
using namespace std;
string reverseS(string st){
	 string res = st;
	 reverse(res.begin(), res.end());
	 return res;
}
string reverseStr(string s){
	stack<string>stackStrings = *(new stack<string>());
	string topS = "";
	for(int i=0;i<s.length();i++){
		if( s[i] == '('){
			stackStrings.push(topS);
			topS="";
		}else if(s[i] == ')'){
			topS = reverseS(topS);
			topS = stackStrings.top()+topS;
			stackStrings.pop();
		}else topS+=s[i];
	}
	return topS;
}
int main(){
	string input = "";
	cin >> input;
	cout << input << endl;
	cout << reverseStr(input);
}