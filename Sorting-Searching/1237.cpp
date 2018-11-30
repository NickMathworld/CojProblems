#include <bits/stdc++.h>
#define MAXN 10007
using namespace std;
string names[MAXN];
vector< pair<int,int> >Lowest;
vector< pair<int,int> >Highest;
bool cmp(pair<int,int> current, int value){
	return current.first < value;
}
int main(){
	int t;
	int n;
	int k;
	cin >> t;
	while(t--){
		cin >> n;
		Lowest.clear();
		Highest.clear();
		for(int i=0;i<n;i++){
			int low,high;
			cin >> names[i];
			cin >> low >> high;
			Lowest.push_back(make_pair(low,i));
			Highest.push_back(make_pair(high,i));
		}
		sort(Lowest.begin(),Lowest.end());
		sort(Highest.begin(),Highest.end());
		cin >> k;
		while(k--){
			int Price;
			cin >> Price;
			int lowBound = lower_bound(Lowest.begin(),Lowest.end(), make_pair(Price,Price))-Lowest.begin();
			int UpBound  = upper_bound(Highest.begin(),Highest.end(), make_pair(Price,Price))-Highest.begin();
			cout << lowBound << " --- " << UpBound << endl;
		}
	}
} 	