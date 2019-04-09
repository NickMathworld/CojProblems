#include<bits/stdc++.h>
using namespace std;
class backpack{
    private:
        string nombre;
        string apellido_paterno;
        string apellido_materno;
        int edad;
        double estatura;
    public:
        backpack(string _nombre,string _apellido_paterno, string _apellido_materno, int _edad, double _estatura)
        :nombre(_nombre),
        apellido_paterno(_apellido_paterno),
        apellido_materno(_apellido_materno),
        edad(_edad),estatura(_estatura){
            cout << "Object created" << endl;
        }
        string to_string(){
            return nombre+" "+apellido_paterno+" "+apellido_materno;
        }
};
int main(){
    cout << "Hola mundo";
    backpack mochila = *(new backpack("nick","zuniga","uribe",24,1.70));
    cout << mochila.to_string() << endl;
    return 0;
}