#include <cstdio>
#include <cstdlib>
#include <string.h>
int main()
{
	char alphabet[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int sumInt = 0;
	char N[101];
	scanf("%s", N);
	for (int i = 0; i < strlen(N); i++)
	{
		sumInt += (N[i] - '0');
	}
	if (sumInt == 0)
	{
		printf("%s", alphabet[0]);
		system("pause");
		return 0;
	}
	int sum[20];
	int count = 19;
	while (sumInt > 0)
	{
		sum[count] = sumInt % 10;
		count--;
		sumInt = sumInt / 10;
	}
	for (int j = count + 1; j < 20;j ++)
	{
		if (j != 19)
		{
			printf("%s ", alphabet[sum[j]]);
		}else
		{
			printf("%s", alphabet[sum[j]] );
		}
	}
	system("pause");
	return 0;

}