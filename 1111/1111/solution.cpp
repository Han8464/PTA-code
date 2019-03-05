/*
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int gra_dis[510][510] = {0};
int gra_time[510][510] = {0};
vector<vector<int>> allpath;
vector<int> path;
int n, m;
bool visit[510];

typedef struct Result
{
	int index;
	int dis;
	int time;
	int num;
}Result;
void dfs(int a, int b)
{
	if(a == b)
	{
		path.push_back(a);
		allpath.push_back(path);
		return;
	}
	path.push_back(a);
	visit[a] = true;
	for(int i = 0; i < n; i++)
	{
		if(gra_dis[a][i] != 0 && visit[i] ==  false)
		{
			dfs(i, b);
			path.pop_back();
			visit[i] = false;
		}
	}
}
int comp_dis(Result* r1, Result* r2)
{
	if(r1->dis == r2->dis)
		return r1->time < r2->time;
	return r1->dis < r2->dis;
}
int comp_time(Result* r1, Result* r2)
{
	if(r1->time == r2->time)
		return r1->num < r2->num;
	return r1->time < r2->time;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		visit[n] = false;
	}
	for(int i = 0; i < m; i++)
	{
		int t1, t2, tag, dis, time;
		scanf("%d%d%d%d%d", &t1, &t2, &tag, &dis, &time);
		if(tag == 0)
		{
			gra_dis[t1][t2] = gra_dis[t2][t1] = dis;
			gra_time[t1][t2] = gra_time[t2][t1] = time;
		}else
		{
			gra_dis[t1][t2] = dis;
			gra_time[t1][t2] = time;
		}
	}
	int q1, q2;
	scanf("%d%d", &q1, &q2);
	dfs(q1, q2);
	int mindis;
	int mintime;
	int dis_index, time_index;
	vector<Result*> results;
	for(int i = 0; i < allpath.size(); i++)
	{
		int totaldis = 0;
		int totaltime = 0;
		vector<int> tmp = allpath[i];
		for(int x = 0; x < tmp.size(); x++)
		{
			if(x != tmp.size() - 1)
			{
				totaldis += gra_dis[tmp[x]][tmp[x + 1]];
				totaltime += gra_time[tmp[x]][tmp[x + 1]];
			}
		}
		Result* r = new Result;
		r->index = i;
		r->dis = totaldis;
		r->time = totaltime;
		r->num = tmp.size();
		results.push_back(r);
	}
	sort(results.begin(), results.end(), comp_dis);
	dis_index = results[0]->index;
	mindis = results[0]->dis;
	sort(results.begin(), results.end(), comp_time);
	time_index = results[0]->index;
	mintime = results[0]->time;
	if(dis_index == time_index)
	{
		printf("Distance = %d; Time = %d: ", mindis, mintime);
		vector<int> ans = allpath[dis_index];
		for(int y = 0; y < ans.size();y++)
		{
			if(y == ans.size() - 1)
			{
				printf("%d\n", ans[y]);
			}else
			{
				printf("%d -> ", ans[y]);
			}
		}
	}else
	{
		printf("Distance = %d: ",mindis);
		vector<int> ans = allpath[dis_index];
		for(int y = 0; y < ans.size();y++)
		{
			if(y == ans.size() - 1)
			{
				printf("%d\n", ans[y]);
			}else
			{
				printf("%d -> ", ans[y]);
			}	
		}
		printf("Time = %d: ", mintime);
		vector<int> ans1 = allpath[time_index];
		for(int y = 0; y < ans1.size();y++)
		{
			if(y == ans1.size() - 1)
			{
				printf("%d\n", ans1[y]);
			}else
			{
				printf("%d -> ", ans1[y]);
			}
		}
	}
	system("pause");
	return 0;

}*/