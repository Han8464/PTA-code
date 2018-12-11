#include <cstdio>
#include <cstdlib>

int main()
{
	int n;
	scanf("%d", &n);
	int num = 0;
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			n = n / 2;
			num++;
		}else
		{
			n = (3*n + 1) / 2;
			num++;
		}
	}
	printf("%d", num);
	system("pause");
	return 0;
}