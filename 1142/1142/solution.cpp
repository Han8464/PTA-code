#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int gra[210][210] = {0};
int main()
{
	int nv, ne;
	scanf("%d%d", &nv, &ne);
	for(int i = 0; i < ne; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		gra[a][b] = gra[b][a] = 1;
	}
	for(int i = 0; i <= nv; i++)
	{
		gra[i][i] = 1;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		vector<int> query;
		vector<int> allNodes(nv + 1, 0);
		for(int j = 0; j < k; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			query.push_back(tmp);
			allNodes[tmp] = 1;
		}
		int tag = 0;
		for(int j = 0; j < k; j++)
		{
			for(int x = 0; x < k; x++)
			{
				if(gra[query[j]][query[x]] == 0)
				{
					printf("Not a Clique\n");
					tag = 1;
					break;
				}
			}
			if(tag == 1)
				break;
		}
		if(tag == 0)
		{
			int num = 0;
			for(int y = 1; y <= nv; y++)
			{
				if(allNodes[y] == 0)
				{
					int edges = 0;
					for(int z = 0; z < k; z++)
					{
						if(gra[query[z]][y] == 0)
						{
							break;
						}
						if(gra[query[z]][y] == 1)
						{
							edges ++;
						}
					}
					if(edges == k)
					{
						printf("Not Maximal\n");
						num = 1;
						break;
					}
				}
				
			}
			if(num == 0)
			{
				printf("Yes\n");
			}
		}
		
	}
	system("pause");
	return 0;
}