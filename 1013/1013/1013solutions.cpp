#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int highways[1010][1010] = {0};
int n, m, k;
int visited[1010];
void dfs(int node)
{
	visited[node] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(highways[node][i] == 1 && visited[i] == 0)
		{
			dfs(i);
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		highways[a][b] = highways[b][a] = 1;
	}
	
	for(int i = 0; i < k; i++)
	{
		int cnt = 0;
		fill(visited, visited + 1010, 0);
		int city;
		scanf("%d", &city);
		visited[city] = 1;
		for(int j = 1; j <= n; j++)
		{
			if(visited[j] == 0)
			{
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}

	system("pause");
	return 0;

}