#include <bits/stdc++.h>
using namespace std;
int input;
void imprime(int n);
int main(){
	int k;
	cin >> k;
	while(k--){
		cin >> input;
		imprime(input);
	}
}

void imprime(int n){
	cout << n%10;
	n/=10;
	while(n){
		cout <<" " <<n%10;
		n/=10;
	}
	cout << "\n";
}