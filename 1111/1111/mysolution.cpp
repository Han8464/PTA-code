#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
typedef struct Edge
{
	int v;
	int dis;
	int time;
	Edge(int v1, int diss, int timee)
	{
		v = v1;
		dis = diss;
		time = timee;
	}
}Edge;
vector<Edge*> gra[550];
int path[550];
int visit[550];
int n, m;//n¸öµã£¬mÌõ±ß
int dist[550], tim[550];
void getpath(vector<int> & p, int x){
	if(x != -1){
		getpath(p, path[x]);
		p.push_back(x);
	}
}
void dij_dis(int s)
{
	for(int i = 0; i < n; i++)
	{
		visit[i] = 0;
		dist[i] = tim[i] = INF;
		path[i] = -1;
	}
	dist[s] = tim[s] = 0;
	for(int i = 0; i < n; i++)
	{
		int u = -1;
		int mind = INF;
		for(int j = 0; j < n; j++)
		{
			if(visit[j] == 0 && dist[j] < mind)
			{
				mind = dist[j];
				u = j;
			}
		}
		visit[u] = 1;
		for(int x = 0; x < gra[u].size(); x++)
		{
			int u_nei = gra[u][x]->v;
			int u_d = gra[u][x]->dis;
			int u_time = gra[u][x]->time;
			if(visit[u_nei] == 0)
			{
				if(dist[u_nei] > dist[u] + u_d)
				{
					dist[u_nei] = dist[u] + u_d;
					tim[u_nei] =  tim[u] + u_time;
					path[u_nei] = u;
				}else if(dist[u_nei] == dist[u] + u_d)
				{
					if(tim[u_nei] > tim[u] + u_time)
					{
						tim[u_nei] =  tim[u] + u_time;
						path[u_nei] = u;
					}
				}
			}
		}

	}
}
void dij_time(int s)
{
	for(int i = 0; i < n; i++)
	{
		path[i] = -1;
		dist[i] = tim[i] = INF;
		visit[i] = 0;
	}
	dist[s] = tim[s] = 0;
	for(int i = 0; i < n; i++)
	{
		int u = -1;
		int mint = INF;
		for(int j = 0; j < n; j++)
		{
			if(visit[j] == 0 && tim[j] < mint)
			{
				mint = tim[j];
				u = j;
			}
		}
		visit[u] = 1;
		for(int x = 0; x < gra[u].size(); x++)
		{
			int u_nei = gra[u][x]->v;
			int u_time = gra[u][x]->time;
			if(visit[u_nei] == 0)
			{
				if(tim[u_nei] > tim[u] + u_time)
				{
					tim[u_nei] = tim[u] + u_time;
					path[u_nei] = u;
					dist[u_nei] = dist[u] + 1;
				}else if(tim[u_nei] == tim[u] + u_time)
				{
					if(dist[u_nei] > dist[u] + 1)
					{
						path[u_nei] = u;
						dist[u_nei] = dist[u] + 1;
					}
				}
			}
		}
	}

}
void print_path(vector<int> & p)
{
	for(int i=0;i<p.size();i++){
		if(i != 0)cout<<" -> ";
		cout<<p[i];
	}cout<<endl;

}
int main()
{

	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int v1, v2, tag, dis, time;
		cin>>v1>>v2>>tag>>dis>>time;
		gra[v1].push_back(new Edge(v2, dis, time));
		if(tag == 0)
			gra[v2].push_back(new Edge(v1, dis, time));
	}
	int s, e;
	cin>>s>>e;
	dij_dis(s);
	int ans_dis = dist[e];
	vector<int> path_dis;
	getpath(path_dis, e);
	dij_time(s);
	int ans_time = tim[e];
	vector<int> path_tim;
	getpath(path_tim, e);
	if(path_dis == path_tim){
		printf("Distance = %d; Time = %d: ", ans_dis, ans_time);print_path(path_dis);
	}else{
		printf("Distance = %d: ",ans_dis);print_path(path_dis);
		printf("Time = %d: ",ans_time);print_path(path_tim);
	}
	system("pause");
	return 0;
}