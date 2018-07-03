#include <cstdio>
#include <cstdlib>
#include <cmath>
bool Isprime(int reverse)
{
	if(reverse == 0 || reverse ==1)
	{
		return false;
	}
	int k = sqrt((double)reverse);
	for (int m = 2; m <= k;m ++)
	{
		if (reverse % m == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n,d;
	scanf("%d",&n);
	int record[1000];
	int cases = 0;
	while (n >= 0)
	{
		scanf("%d",&d);
		if(Isprime(n) == false)
		{
			record[cases] = 0;
			cases ++;
			scanf("%d",&n);
			continue;
		}
		int num[10000];
		int count = 0;
		int reverse = 0;
		while(n > 0)
		{
			num[count] = n % d;
			n = n / d;
			count++;
		}
		int j = 0;
		for(int i = count - 1; i >= 0; i--)
		{
			reverse += (num[i] * pow((double)d,j));
			j++;
		}
		if((Isprime(reverse) == true))
		{
			record[cases] = 1;
		}else
		{
			record[cases] = 0;
		}
		cases ++;
		scanf("%d",&n);
	}
	cases -= 1;
	int tmp = 0;
	while(tmp <= cases)
	{
		if(record[tmp] == 1)
		{
			printf("Yes\n");
		}else
		{
			printf("No\n");
		}
		tmp ++;
	}
		system("pause");
		return 0;

}