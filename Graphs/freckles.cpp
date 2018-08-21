#include <bits/stdc++.h>
using namespace std;
vector< pair<double,double> >points;
priority_queue< pair< double,pair <int,int> > >edges;
class UnionFind{
	private:
		int nodes;
		vector<int>parents;
	public:
		UnionFind(int n_max):nodes(n_max){
			for(int i=0;i<n_max;i++)
				parents.push_back(i);
		}
		int Find(int son){
			if(parents[son] == son)
				return son;
			return parents[son] = Find(parents[son]);
		}
		void Union(int x, int y){
			int father_x = Find(x);
			int father_y = Find(y);
			parents[father_x] = father_y;
		}
};
double Point_Distace(pair<double,double>p1, pair<double,double>p2){
	return sqrt( pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}
double Kruskal( priority_queue< pair< double,pair <int,int> > >edg, int N){
	UnionFind UF = *(new UnionFind(N));
	double res = 0;
	while(!edges.empty()){
		auto nodes = edges.top().second;
		if( UF.Find(nodes.first) != UF.Find(nodes.second) )
			UF.Union(nodes.first,nodes.second),res+=edges.top().first;
		edges.pop();
	}
	return res;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	int n;
	cin >> t;
	for(int k =0;k<t;k++){
		points.clear();
		while(!edges.empty())edges.pop();
		cin >> n;
		while(n--){
			double x,y;// Auxiliar variables for new point
			cin >> x >> y;
			points.push_back( make_pair(x,y) );
		}
		for(int i=0;i<points.size();i++)
			for(int j=i+1;j<points.size();j++)
				edges.push(  make_pair( -1*Point_Distace(points[i],points[j]),make_pair(i,j)));
		if( k > 0)
			printf("\n");
	 	printf("%.2lf\n",-1*Kruskal(edges,points.size()));
	}
	
}	