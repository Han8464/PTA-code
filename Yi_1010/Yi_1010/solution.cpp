#include <cstdio>
#include <cstdlib>

int main()
{
	int a, b;
	int n = 1;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		if (n == 1 && b == 0)
		{
			printf("%d %d", 0, 0);
		}
		if(b != 0)
		{
			if( n == 1)
			{
				printf("%d %d", a * b, b - 1);
				n++;
			}else
			{
				printf(" %d %d", a * b, b - 1);
			}
		}
	}
	return 0;
}