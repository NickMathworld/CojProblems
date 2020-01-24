#include <bits/stdc++.h>
#define lld long long
using namespace std;
char input[1000];
void deleteComma(char *arr);
int main(){
	int it = 0;
	while(scanf("%s,",input)!= EOF){
		deleteComma(input);
		printf("Nombre %d: %s\n",++it,input);
	}
}
void deleteComma(char *arr){
	for(int i=0;i<strlen(arr);i++)
		if(arr[i] == ','){
			arr[i] = 0;
			return;
		}
}