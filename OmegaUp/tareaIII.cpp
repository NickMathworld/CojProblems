#include <bits/stdc++.h>
#define lld long long
using namespace std;
char nombres[3][1000];
char apellidoP[3][1000];
char apellidoM[3][1000];
void deleteComma(char *arr);
int main(){
	int it = 0;
	scanf("%s %s %s %s %s %s %s %s %s",nombres[0],nombres[1],nombres[2],apellidoP[0],apellidoP[1],apellidoP[2],apellidoM[0],apellidoM[1],apellidoM[2]);
	for(int i=0;i<3;i++){
		deleteComma(nombres[i]);
		deleteComma(apellidoP[i]);
		deleteComma(apellidoM[i]);
		printf("Nombre %d: %s\n",i+1,nombres[i]);
		printf("Apellido Paterno %d: %s\n",i+1,apellidoP[i]);
		printf("Apellido Materno %d: %s\n",i+1,apellidoM[i]);
	}

}
void deleteComma(char *arr){
	for(int i=0;i<strlen(arr);i++)
		if(arr[i] == ','){
			arr[i] = 0;
			return;
		}
}