#include <bits/stdc++.h>
using namespace std;
int getDivisors(string s){
	int x = 0;
	int res = 1;
	for(int i=0;i<s.size();i++)
		x+=toupper(s[i]);
	for(int i=2;i*i<=x;i++){
		int PP=0;
		if(x%i == 0)
			while(x%i ==0)
				x/=i,PP++;
		res*=PP+1;
	}
	if(x != 1)
		res*=2;
	return res;
}
int main(){
	string s;
	cin >> s;
	cout << getDivisors(s) << "\n";
}