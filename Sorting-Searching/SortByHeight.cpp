#include <bits/stdc++.h>
using namespace std;

void imprime(vector<int> v){
	for(int i=0;i<v.size();i++)
		cout << " " << v[i];
	cout << endl;
}
vector<int>sortByHeight(vector<int> a){
	vector<int>res = *(new vector<int>());
	vector<int>Trees = *(new vector<int>());
	Trees.push_back(-1);
	for(int i=0;i<a.size();i++)
		if(a[i] == -1)
			Trees.push_back(i);
	sort(a.begin(),a.end());
	int indice = 0;
	int TreeIndex = Trees.size()>1;
	int LastItem = 0;
	for(int i=0;i<a.size();i++){
		if(Trees[TreeIndex] == LastItem){
			res.push_back(-1),TreeIndex++,LastItem++,i--;
			continue;
		}
		if(a[i] == -1)
			continue;
		res.push_back(a[i]);
		LastItem++;
	}
	if(Trees.size() > 1)
		for(int i=TreeIndex;i<Trees.size();i++)
			res.push_back(-1);
	return res;
}
int main(){
	vector<int>input = *(new vector<int>());
	int aux;
	while(cin >> aux)
		input.push_back(aux);
	imprime( sortByHeight(input) );
}