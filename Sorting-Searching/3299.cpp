#include <bits/stdc++.h>
using namespace std;
double n1,n2;
double a,b;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin >> a >> b){
		if(!a and !b)
			return 0;
		n1 = (-1+sqrt(1+8*(a-1)))/2;
		n2 = (-1+sqrt(1+8*b))/2;
		long long nMin = n1;
		long long nMax = n2;
		cout << nMax-nMin << "\n";
	}
}