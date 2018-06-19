#include<bits/stdc++.h>
using namespace std;
string cad;
string a1,a2;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> cad;
	int n = cad.size()/2;
	for(int i=0;i<n;i++)
		a1+=cad[n-i-1];
	for(int i=n;i<cad.size()-cad.size()%2;i++)
		a2+=cad[cad.size()-i-1+n];
	if(cad.size()%2)
		a1+=cad[n];
	cout << a1+a2 << "\n";
} 	