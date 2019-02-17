#include <cstdio>
#include <cstdlib>
#include <math.h>

bool IsPrime(int p)
{
	int tag = 0;
	if(p == 2 || p == 3)
	{
		return true;
	}
	if(p % 6 != 1 && p % 6 != 5)
	{
		return false;
	}
	int tmp = sqrt((double)p);
	for(int i = 5; i < tmp; i += 6)
	{
		if(p % i == 0 || p % (i + 2) == 0)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int l,k;
	scanf("%d%d", &l, &k);
	char num[1010];
	getchar();
	for(int i = 0; i < l; i++)
	{
		scanf("%c", &num[i]);
	}
	for(int j = 0; j < l; j ++)
	{
		int p = 0;
		if(j + k < l)
		{
			for(int a = 0; a < k; a++)
			{
				//printf("j + a: %c\n", num[j + a]);
				p += (num[j + a] - '0') * pow(10.0, k - a - 1);
			}
			//printf("p: %d\n", p);
		}else
		{
			p = -1;
		}


		if(p != -1 && IsPrime(p))
		{
			printf("%0*d", k, p);
			system("pause");
			return 0;
		}
	}
	printf("404");
	system("pause");
	return 0;
}