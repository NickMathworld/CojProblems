#include<bits/stdc++.h>
using namespace std;
bool IsLucky(string num){
	int FirstHalf = 0;
	int SecondHalf = 0;
	for(int i=0;i<num.size()/2;i++)
		FirstHalf+=num[i]-'0';
	for(int i=num.size()/2;i<num.size();i++)
		SecondHalf+=num[i]-'0';
	return FirstHalf == SecondHalf;
}
int main(){
	string k = "";
	cin >> k;
	cout << IsLucky(k);
	
	return 0;
}