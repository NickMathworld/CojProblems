#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
map<int,bool>Circle;
int points[MAXN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	while(cin >> t){
		Circle.clear();
		int suma = 0;
		for(int i=0;i<t;i++){
			cin >> points[i];
			suma+=points[i];
			points[i] = suma;
			Circle[ points[i] ]=1;
		}
		if(suma%3)
			cout << "0\n";
		else{
			int next = suma/3;
			int res = 0;
			for(int i=0;i<t;i++)
				if( Circle.find((points[i]+next)%suma)!= Circle.end() and Circle.find((points[i]+2*next)%suma)!= Circle.end() )
					if(Circle[(points[i]+next)%suma] and Circle[(points[i]+2*next)%suma])
						res++,Circle[(points[i]+next)%suma] = false, Circle[(points[i]+2*next)%suma] = false, Circle[points[i]]=false;
			cout << res << "\n";
		}
	}
}