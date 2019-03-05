/*
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 505,INF= 999999999;
int n,m;
struct edge{
	int v,d,t;
	edge(int vv = 0,int dd = 0,int tt = 0):v(vv),d(dd),t(tt){}
};
vector<edge> G[maxn];
int vis[maxn],dist[maxn],tim[maxn],cnt[maxn],path[maxn];
void get_path(int x,vector<int> & p){
	if(x != -1){
		get_path(path[x],p);
		p.push_back(x);
	}
}
void print_path(const vector<int> & vec){
	for(int i=0;i<vec.size();i++){
		if(i != 0)cout<<" -> ";
		cout<<vec[i];
	}cout<<endl;
}
void dijkstra1(int x){
	for(int i=0;i<n;i++)
	{
		path[i] = -1;
		dist[i] = tim[i] = INF;
		vis[i] = 0;
	}//初始化
	dist[x] = tim[x] = 0;//记录初始节点
	for(int j=0;j<n;j++){
		int u = -1,mind = INF;
		for(int i=0;i<n;i++)
		{
			if(vis[i] == 0 && mind > dist[i])
				mind = dist[u = i];
		}
		vis[u] = 1;
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i].v,d = G[u][i].d,t = G[u][i].t;
			if(vis[v] == 0){
				if(dist[v] > dist[u] + d){
					dist[v] = dist[u] + d;
					tim[v] = tim[u] + t;
					path[v] = u;
				}else if(dist[v] == dist[u] + d && tim[v] > tim[u] + t){
					tim[v] = tim[u] + t;
					path[v] = u;
				}
			}
		}
	}
}
void dijkstra2(int x){
	for(int i=0;i<n;i++){path[i] = -1;cnt[i] = INF;tim[i] = INF;vis[i] = 0;}
	cnt[x] = tim[x] = 0;
	for(int j=0;j<n;j++){
		int u = -1,mint = INF;
		for(int i=0;i<n;i++)if(vis[i] == 0 && mint > tim[i])mint = tim[u = i];
		vis[u] = 1;
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i].v,t = G[u][i].t;
			if(vis[v] == 0){
				if(tim[v] > tim[u] + t){
					tim[v] = tim[u] + t;
					cnt[v] = cnt[u] + 1;
					path[v] = u;
				}else if(tim[v] == tim[u] + t && cnt[v] > cnt[u] + 1){
					cnt[v] = cnt[u] + 1;
					path[v] = u;
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c,d,t;
		cin>>a>>b>>c>>d>>t;
		G[a].push_back(edge(b,d,t));
		if(c == 0)G[b].push_back(edge(a,d,t));
	}
	int t,d,s,e;
	cin>>s>>e;
	vector<int> path1,path2;
	dijkstra1(s);
	d = dist[e];
	get_path(e,path1);
	dijkstra2(s);
	t = tim[e];
	get_path(e,path2);
	if(path2 == path1){printf("Distance = %d; Time = %d: ",d,t);print_path(path1);}
	else{
		printf("Distance = %d: ",d);print_path(path1);
		printf("Time = %d: ",t);print_path(path2);
	}
	return 0;

}*/