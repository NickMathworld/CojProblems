#include<bits/stdc++.h>
using namespace std;

int numero[100009];
int arreglo[4];

int dp(int num,int moneda)
{
	
	if(num<0)return 999999;
	if(numero[num])return numero[num];
	if(moneda == 3)return num;
	return numero[num] = min(1 + dp(num-arreglo[moneda],moneda),1+dp(num-arreglo[moneda+1],moneda+1) );
}

int n;
int num;
int i;
int main(void)
{
	arreglo[0] = 6;
    arreglo[1] = 5;
	arreglo[2] = 3;
	arreglo[3] = 1;
	numero[0] = 0;
	numero[1] = 1;
	numero[2] = 2;
	numero[3] = 1;
	numero[4] = 2;
	numero[5] = 1;
	numero[6] = 1;
	numero[7] = 2;
	numero[8] = 2;
	numero[9] = 2;
	for(i=0;i<100007;i++)dp(i,0);
	scanf("%d",&n);
	i = 0;
	while(i++!=n)
	{
		scanf("%d",&num);
		printf("Case %d: %d\n",i,numero[num]);
	}
}