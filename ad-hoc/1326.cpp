#include <bits/stdc++.h>
using namespace std;
int n,t,k;// Initial Balance Account and test cases
char QT;
int money;
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		cin >> k;
		while(k--){
			cin >> QT >> money;
			n+=money*(QT == 'C'?1:-1);
		}
		cout << n << "\n";
	}
}