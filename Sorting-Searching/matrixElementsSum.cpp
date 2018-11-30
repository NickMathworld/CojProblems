#include <bits/stdc++.h>
using namespace std;
void imprime(std::vector<string> v){
	for(int i=0;i<v.size();i++)
		cout << v[i] << "," << endl;
}
std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
    int maxSize = -1;
    vector<string>res = *(new vector<string>());
    for(int i=0;i<inputArray.size();i++){
        int aux = inputArray[i].size();
        maxSize = max(aux,maxSize);
    }
    for(int i=0;i<inputArray.size();i++)
        if( inputArray[i].size() == maxSize)
            res.push_back( inputArray[i] );
    imprime(res);
    return res;
}
int main(){
	vector<string> palabras= *(new std::vector<string>());
	palabras.push_back("aba");
	palabras.push_back("aa");
	palabras.push_back("ad");
	palabras.push_back("vcd");
	palabras.push_back("aba");
	allLongestStrings(palabras);
}