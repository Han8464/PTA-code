#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
typedef struct Edge
{
	int a, b;
}Edge;
Edge edges[10010];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &edges[i].a, &edges[i].b);
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		int v;
		scanf("%d", &v);
		set<int>query;
		for(int j = 0; j < v; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			query.insert(tmp);
		}
		int tag = 0;

		for(int x = 0; x < m; x++)
		{
			if(query.find(edges[x].a) == query.end() && query.find(edges[x].b) == query.end())
			{
				printf("No\n");
				tag = 1;
				break;
			}
		}
		if(tag == 0)
			printf("Yes\n");
	}
	system("pause");
	return 0;

}