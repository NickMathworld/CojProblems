#include <bits/stdc++.h>
using namespace std;
int fac[6];
void preCalc(){
	fac[0] = 1;
	for(int i=1;i<=5;i++)
		fac[i]=fac[i-1]*i;
}
int ACM(int k){
	int res = 0;
	int it = 1;
	while(k)
		res+=fac[it++]*(k%10),k/=10;
	return res;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	preCalc();
	int k;
	while( cin >> k and k)
		cout << ACM(k) << "\n";
}