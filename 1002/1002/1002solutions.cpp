#include <cstdio>
#include <cstdlib>

int main()
{
	double co1[1010] = {0.0};
	double co2[1010] = {0.0};
	int result_ex[11];
	double result_co[1010];
	int k1;
	int k2;
	scanf("%d", &k1);
	for(int i = 0; i < k1;i++)
	{
		int tmp;
		scanf("%d", &tmp);
		scanf("%lf", &co1[tmp]);
	}
	scanf("%d", &k2);
	for(int i = 0; i < k2; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		scanf("%lf", &co2[tmp]);
	}
	int index = 0;
	for(int i = 1009; i >= 0; i--)
	{
		co2[i] = co2[i] + co1[i];
		if(co2[i] != 0)
		{
			index ++;
		}
	}
	if(index != 0)
	{
		printf("%d ", index);
	}else
	{
		printf("%d", index);
		return 0;
	}
	index = index - 1;
	for(int i = 1009; i >= 0; i--)
	{
		if(co2[i] != 0 && index == 0)
		{
			printf("%d %.1f", i, co2[i]);
		}else if(co2[i] != 0 && index != 0)
		{
			printf("%d %.1f ", i, co2[i]);
			index --;
		}
	}
	system("pause");
	return 0;
}