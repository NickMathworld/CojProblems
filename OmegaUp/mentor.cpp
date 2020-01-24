#include <iostream>
#include <string>
 
using namespace std;
 
int main(int argc, char *argv[]){
    int j,x,f,c,g;
    string materia[14];
    float notas[14][4],promgrl;
    //ingreso de las materias
	for(g=1;g<=4;g++){
		cout<<"ingresa la materia : "<<endl;
	}
    //ingreso de notas
    for (j=1;j<=4;j++){
        for(x=1;x<=3;x++){
            cout<<"Ingrese la nota de la materia "<<j<<": ";
        cin>>notas[j][x];
        if (notas[j][x]>10){
            cout<<"Ingrese una nota real"<<endl;
            x--;
            }
        }
    }
    //suma de notas
    for (f=1;f<=4;f++){
        notas[f][4]=0;
        for(c=1;c<=3;c++){
            notas[f][4]=notas[f][4]+notas[f][c];
        }
    }
    //calculo del promedio
    for (f=1;f<=4;f++){
        notas[f][4]=((notas[f][4])/3);
    }
    //muestra de la matriz
    for (f=1;f<=4;f++){
        for (c=1;c<=4;c++){
            cout<<notas[f][c]<<"  ";
        }
        cout<<endl;
    }
    //calculo del promedio general
    for (f=1;f<=4;f++){
        promgrl=promgrl+notas[f][4];
    }
    promgrl=promgrl/4;
    cout<<"Promedio general: "<<promgrl<<endl;
 
    system("pause");
}
 
