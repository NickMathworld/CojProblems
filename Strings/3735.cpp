#include <bits/stdc++.h>
using namespace std;
int letras[30];
int n;
string LowerPol(string st){
	memset(letras,0,sizeof(letras));
	
	string in,end;
	string mid = "";
	in = end = "";
		
	sort(end.begin(),end.end());
	for(int i=0;i<st.size();i++)
		letras[st[i]-'A']++;
	for(int i=0;i<30;i++){
		if(letras[i]%2 and mid == "")
			mid += (i+'A');
		if(letras[i]%2)
			letras[i]--;
		while(letras[i]!=0)
				in+=(i+'A'),end+=(i+'A'),letras[i]-=2;
	}
	reverse(end.begin(), end.end());
	return in+mid+end;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	string str;
	cin >> n;
	while(n--){
		cin >> k;
		cin >> str;
		cout << LowerPol(str) << endl;
	}
}