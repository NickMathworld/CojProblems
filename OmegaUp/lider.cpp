#include <bits/stdc++.h>
using namespace std;
#define lld long long
lld n,m;
string res;

class BigNumber{
	public:
		string number;
		BigNumber(string number){
			this->number = number;
		}
};

string reverseS(string s){
	string ans = "";
	for(int i=s.size()-1;i>=0;i--)
		ans+=s[i];
	return ans;
}

string ToString(lld number){
	string ans = "";
	while(number)
		ans+=number%10+'0',number/=10;
	return reverseS(ans);
}


BigNumber operator*(const BigNumber &n1, const BigNumber &n2){
	string s1 = reverseS(n1.number);
	string s2 = reverseS(n2.number);
	string ans = "";
	int arr[100];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<s1.size();i++)
		for(int j=0;j<s2.size();j++)
			arr[i+j]+= ( (s1[i]-'0')*(s2[j]-'0'));
	int carry = 0;
	int aux = 0;
	for(int i=0;i<100;i++){
		aux = arr[i]+carry;
		arr[i] = (arr[i]+carry)%10;
		carry = aux/10;
	}
	bool NoZero = false;
	for(int i=99;i>=0;i--){
		if(arr[i] != 0)
			NoZero = true;
		if(NoZero)
			ans+=arr[i]+'0';
	}
	return *(new BigNumber(ans));
}

int main(){
	BigNumber n1 = *(new BigNumber(""));
	BigNumber n2 = *(new BigNumber(""));
	BigNumber n3 = *(new BigNumber(""));
	cin >> n >> m;
	if(m == 0){
		cout << 0;
		return 0;
	}
	n1.number = ToString(m);
	if( n%2 ){
		n2.number = ToString(n);
		n3.number = ToString((n+1)/2);
	}
	else {
		n2.number = ToString(n/2);
		n3.number = ToString(n+1);	
	}
	cout << (n1*n2*n3).number;
}
/*
55
12
--
 (110)
  55
  670
*/