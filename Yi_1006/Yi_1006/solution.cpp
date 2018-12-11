#include <cstdio>
#include <cstdlib>
int main()
{
	int n;
	scanf("%d", &n);
	int tmp = n;
	int bs[4];
	int i = 0;
	while(tmp != 0)
	{
		bs[i] = tmp % 10;
		tmp = tmp / 10;
		i++;
	}
	for(int j = 0; j < bs[2]; j++)
	{
		printf("B");
	}
	for(int j = 0; j < bs[1]; j++)
	{
		printf("S");
	}
	for(int j = 1; j <= bs[0]; j++)
	{
		printf("%d", j);
	}
	system("pause");
	return 0;
}