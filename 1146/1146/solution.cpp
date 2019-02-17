#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int gra[1010][1010] = {0};
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int tmp1, tmp2;
		scanf("%d%d", &tmp1, &tmp2);
		gra[tmp1][tmp2] = 1;
	}
	int k;
	scanf("%d", &k);
	int res[110];
	int r = 0;
	for(int i = 0; i < k; i++)
	{
		int point[6];
		for(int j = 0; j < 6;j++)
		{
			scanf("%d", &point[j]);
		}
		for(int z = 0; z < 6; z++)
		{
			if(gra[point[z]][point[z+1]] == 1 && z == 5)
			{
				res[r] = i;
				r++;
			}else if(gra[point[z]][point[z+1]] == 0)
			{
				break;
			}
			
		}
	}

	if (r == 0)
	{
		printf ("NOT a topological order");
	}else
	{
		for(int i = 0; i < r - 1; i++)
		{
			printf("%d ", res[i]);
		}
		printf ("%d", res[r - 1]);

	}
	system("pause");
	return 0;
}