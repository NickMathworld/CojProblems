#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n,k;
string s;
string parasoul(lld n,lld k);
string To_string(lld n);
int main(){
	int c;
	cin >> c;
	while(c--){
		cin >> n >> k;
		cout << parasoul(n,k) <<  "\n";
	}
}

string parasoul(lld n,lld k){
	lld producto = n*k;
	lld suma = n+k;
	return To_string(producto)+To_string(suma)+To_string(n);
}

string To_string(lld n){
	string ans = "";
	while(n){
		string aux = "";
		aux+=n%10+'0';
		ans = aux+ans;
		n/=10;
	}
	return ans;
}