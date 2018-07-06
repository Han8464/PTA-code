#include <cstdio>
#include <cstdlib>

int main()
{
	int n;
	int dis[100005];
	scanf("%d", &n);
	int total = 0;
	int sum[100005];
	sum[1] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &dis[i]);
		total += dis[i];
		sum[i + 1] = total;
	}
	int m;
	scanf("%d", &m);

	for(int i = 0; i < m; i++)
	{
		int d1 = 0, d2 = 0;
		int start, end;
		scanf("%d%d", &start, &end);
		if(start > end)
		{
			int t = end;
			end = start;
			start = t;
		}
		d1 = sum[end] - sum[start];
		d2 = total - d1;
		if(d1 <= d2)
		{
			printf("%d\n", d1);
		}else
		{
			printf("%d\n", d2);
		}
	}
	system("pause");
	return 0;
}