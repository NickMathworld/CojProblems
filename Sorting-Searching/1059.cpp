#include <bits/stdc++.h>
using namespace std;
long paridad(long k){
	int suma = 0;
	stack<int>bit = *(new stack<int>());
	while(k)
		bit.push(k%2),k>>=1;
	cout << "The parity of ";
	while(!bit.empty()){
		cout << bit.top();
		suma+=bit.top();
		bit.pop();
	}
	cout << " is " << suma << "(mod 2).\n";
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long k;
	while( cin >>k and k)
		paridad(k);
}