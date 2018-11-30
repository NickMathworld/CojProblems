#include <bits/stdc++.h>
#define MAXN 1000000+5
using namespace std;
double dp[MAXN];
double iroot,iLn,iSin;
void PreCalc(){
	dp[0] = 1;
	for(double i=1;i<MAXN;i++){
		iroot = i-sqrt(i);
		iLn = log(i);
		iSin = i*pow(sin(i),2);
		dp[(int)i] = (int)(dp[(int)iLn]+dp[(int)iroot]+dp[(int)iSin])%1000000;
	}	
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	PreCalc();
	int N;
	while(cin >> N and N!= -1){
		cout << dp[N] <<"\n";
	}
}
