#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int n;
string ToBaseM2(int value){
	string ans = "";
	if(!value)
		ans = "0";
	while(value){
		if( value % (-2) < 0 )
			value/=-2,value++,ans+="1";
		else if( value % (-2) > 0)
			value/=-2,ans+="1";
		else value/=-2,ans+="0";
	}
	reverse(ans.begin(), ans.end()); 
	return ans;
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int aux = 0;
		cin >> aux;
		cout << "Case #"<< i+1 << ": " << ToBaseM2(aux) << "\n";
	}
}