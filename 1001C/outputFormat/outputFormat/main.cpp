#include <cstdio>
#include <cstdlib>

int main()
{
	int a,b;
	char sum[20]; 
	bool isMinus = false;
	scanf("%d%d", &a, &b);

	int sumInt = a + b;
	if (sumInt == 0)
	{
		printf ("0");
		return 0;
	}
	if (sumInt < 0)
	{
		isMinus = true;
		sumInt = - sumInt;
	}
	int count = 18;
	sum[19] = '\0';
	int i = 0;
	while(sumInt > 0)
	{
		if (i == 3)
		{
			sum[count] = ',';
			count--;
			i = 0;
		}
		sum[count] = sumInt % 10 + '0';
		count --;
		i++;
		sumInt = sumInt / 10;
	}
	if (isMinus)
	{
		sum[count] = '-';
		count--;
	}
	printf("%s", sum + count + 1);
	system("pause");
	return 0;
}