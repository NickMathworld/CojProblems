#include <bits/stdc++.h>
#define lld long long
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 34
using namespace std;
int n;
lld mem[MAXN][3];

lld dp(int k, int zeros, int n){
	if(mem[k][zeros] != -1)
		return mem[k][zeros];
	if(k == n)
		return 1;
	if(zeros < 2)
		return mem[k][zeros] = dp(k+1,0,n)+dp(k+1,zeros+1,n);
	return mem[k][zeros] = dp(k+1,0,n);
}
int main(){
	optimizar_io
	cin >> n;
	memset(mem,-1,sizeof(mem));
	cout << dp(0,0,n);
}