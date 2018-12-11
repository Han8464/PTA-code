#include <cstdio>
#include <cstdlib>
#include <cmath>

bool judge(int n)
{
	int tmp = sqrt((double)n);
	for(int i = 2; i <= tmp; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	if(n <= 1)
	{
		printf("0");
	}else
	{
		int p = -1;
		int num = 0;
		for(int i = 2; i <= n; i++)
		{
			bool tag = judge(i);
			if(tag && p != -1)
			{
				if(i - p == 2)
				{
					num++;
					p = i;
				}else
				{
					p = i;
				}
			}else if(tag && p == -1)
			{
				p = i;
			}
		}
		printf("%d", num);
	}
	system("pause");
	return 0;
}