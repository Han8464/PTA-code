#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
int graph[10010][10010] = {0};
typedef struct Edge
{
	int n1, n2;
}Edge;
Edge edges[10010];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int v1, v2;
		scanf("%d%d", &edges[i].n1, &edges[i].n2);
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		vector<int> color;
		set<int> number;
		int tag = 0;
		for(int j = 0; j < n; j++)
		{
			int c;
			scanf("%d", &c);
			number.insert(c);
			color.push_back(c);
		}
		for(int x = 0; x < m; x++)
		{
			if(color[edges[x].n1] == color[edges[x].n2])
			{
				tag = 1;
				break;
			}
		}
		if(tag == 0)
		{
			printf("%d-coloring\n", number.size());
		}else
		{
			printf("No\n");
		}
	}
	system("pause");
	return 0;

}