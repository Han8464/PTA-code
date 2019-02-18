#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
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
		vector<int>point;
		int tag = 0;
		for(int j = 0; j < n;j++)
		{
			int t1;
			scanf("%d", &t1);
			point.push_back(t1);
		}
		for(int z = 0; z < n; z++)
		{
			for(int x = z + 1; x <= n; x++)
			{
				if(gra[point[x]][point[z]] == 1)
				{
					res[r] = i;
					r++;
					tag = 1;
					break;
				}
			}
			if(tag == 1)
				break;
		}
	}
	for(int i = 0; i < r - 1; i++)
	{
		printf("%d ", res[i]);
	}
	printf ("%d", res[r - 1]);
	system("pause");
	return 0;
}