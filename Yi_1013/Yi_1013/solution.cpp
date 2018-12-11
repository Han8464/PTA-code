#include <cstdio>
#include <cstdlib>
#include <cmath>

bool judge(int x)
{
	int tmp = sqrt((double)x);
	
	for(int i = 2; i <= tmp; i++)
	{
		if(x % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int index = 0;
	int num = 0;
	for(int i = 2; index < n; i++)
	{
		bool tag = judge(i);
		if(tag && index < m - 1)
		{
			index++;
		}else if(tag && index >= m - 1)
		{
			if(num == 9)
			{
				printf("%d\n", i);
				num = 0;
			}else 
			{
				if(index != n- 1)
				{
					printf("%d ", i);
				}else
				{
					printf("%d", i);
				}

				num++;
			}
			index ++;
		}
	}
	system("pause");
	return 0;

}