#include <bits/stdc++.h>
#define MAXN 101
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
string graph[MAXN];
string instructions;
int n,m,k;
int collectCoins(string graph[],int n, int m,string instructions){
	int res = 0;
	map<char,int>orientation;
	orientation['N'] = 1;
	orientation['S'] = 1;
	orientation['L'] = 1;
	orientation['O'] = 1;
	int x= 0,y= 0;// Cell at the beginning
	char direction = '-';// Direction at the beginning
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(orientation[graph[i][j]] == 1){
				y = i;x = j;direction = graph[i][j];
			}
	for(int i=0;i<instructions.size();i++){
		if(instructions[i] == 'F'){
			if( direction == 'N' and y-1 >= 0)
				if(graph[y-1][x] != '#')
					y-=1;
			if( direction == 'S' and y+1 < n)
				if(graph[y+1][x] != '#')
						y+=1;
			if( direction == 'L' and x+1 < m)
				if(graph[y][x+1] != '#')
					x+=1;
			if( direction == 'O' and x-1 >= 0)
				if(graph[y][x-1] != '#')
					x-=1;
		}
		else if(instructions[i] == 'D'){
			if(direction == 'N')
				direction = 'L';
			else if(direction == 'S')
				direction = 'O';
			else if(direction == 'L')
				direction = 'S';
			else if(direction == 'O')
				direction = 'N';
		}
		else if(instructions[i] == 'E'){
			if(direction == 'N')
				direction = 'O';
			else if(direction == 'S')
				direction = 'L';
			else if(direction == 'L')
				direction = 'N';
			else if(direction == 'O')
				direction = 'S';
		}
		if(graph[y][x] == '*')
			res++,graph[y][x] = '.';
	}
	return res;
}
int main(){
	optimizar_io
	while(cin >> n >> m >> k){
		if(!n and !m and !k)
			return 0;
		for(int i=0;i<n;i++)
			cin >> graph[i];
		cin >> instructions;
		cout << collectCoins(graph,n,m,instructions) << "\n";
	}
}