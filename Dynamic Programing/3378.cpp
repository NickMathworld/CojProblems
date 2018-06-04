#include <bits/stdc++.h>
#define MAXN 100007
#define MOD 1000000007
#define lld long long
using namespace std;
lld mem[100];
lld mem2[200][MAXN];
lld arreglo[MAXN];
lld N;
lld sumDigits(int N){
	int res = 0;
	while(N>0)
		res+=N%10,N/=10;
	return res;
}

lld F( int n ){
	int suma = sumDigits(n);
	if(mem[suma] != -1 )
		return mem[suma];
	if(n < 10)
		return n;
	return mem[suma] = F(suma);
}

lld dp(int acum, int index, int d){
	if( index == N and acum == d)
		return 1;
	if(index == N)
		return 0;
	if(mem2[acum][index] != -1)
		return (mem2[acum][index])%MOD;
	return mem2[acum][index] = 
			(dp( F(acum+arreglo[index]),index+1,d)+dp(acum,index+1,d))%MOD;
}
 
int main(){
	memset(mem,-1,sizeof(mem));
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&arreglo[i]);
		arreglo[i] = F(arreglo[i]);
	}
	for(int i=1;i<10;i++){
		for(int j=0;j<105;j++)
			for(int k=0;k<N;k++)
				mem2[j][k] = -1;
		printf("%d\n",dp(0,0,i));
	}
}