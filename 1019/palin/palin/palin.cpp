#include <cstdio>
#include <cstdlib>
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	int num[10000];
	int count = 0;
	bool sign = true;
	if(n == 0)
	{
		printf("Yes\n");
		printf("%d",0);
		system("pause");
		return 0;
	}
	while (n > 0)
	{
		num[count] = n % d;
		n = n / d;
		count ++;
	}
	int i = 0; 
	int j = count - 1;
	if((i == j) && num[i] >= 10)
		sign = false;
	while(i < j)
	{
		if (num[i] != num[j])
		{
			sign = false;
			break;
		}
		i++;
		j--;
	}
	if(sign)
	{
		printf("Yes\n");
	}else
	{
		printf("No\n");
	}
	for(int k = count - 1; k >= 0; k--)
	{
		if(k != 0)
		{
			printf("%d ",num[k]);
		}else
		{
			printf("%d",num[k]);
		}
	}
	system("pause");
	return 0;
}
