#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 1000000
using namespace std;
map<int,int>bucket;
int n;
pair<int,int> FindAndInsert(int element){
	pair<int,int> res = make_pair(0,0);
	res.second  = bucket.lower_bound(element)->first;
	res.first = bucket.lower_bound(-element)->first;
	bucket[element]++;
	bucket[-element]++;
	return res;
}
int main(){
	optimizar_io
	bucket[0] = 1;
	bucket[1000000] = 1;
	cin >> n;
	while( n-- ){
		int element;
		cin >> element;
		pair<int,int> aux = FindAndInsert(element);
		cout << abs(aux.first) << " " << abs(aux.second) << "\n";
	}
}