#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int num[1010];
	int a1 = 0;//能被 5 整除的数字中所有偶数的和；
	int a2[1010];//将被 5 除后余 1 的数字按给出顺序进行交错求和
	int a2N = 0;
	int a3 = 0;//被 5 除后余 2 的数字的个数
	int a4 = 0, a4N = 0;//被 5 除后余 3 的数字的平均数
	set<int> a5_set;//被 5 除后余 4 的数字中最大数字
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if(tmp % 5 == 0 && tmp % 2 == 0 && tmp != 0)
		{
			a1 += tmp;
		}
		if(tmp % 5 == 1)
		{
			a2[a2N] = tmp;
			a2N++;
		}
		if(tmp % 5 == 2)
		{
			a3++;
		}
		if(tmp % 5 == 3)
		{
			a4 += tmp;
			a4N++;
		}
		if(tmp % 5 == 4)
		{
			a5_set.insert(tmp);
		}
	}
	if(a1 != 0)
	{
		printf("%d", a1);
	}else
	{
		printf("N");
	}
	if(a2N == 0)
	{
		printf(" N");
	}else
	{
		int res2 = 0;
		for(int i = 0; i < a2N; i += 2)
		{
			if(i != a2N - 1)
			{
				res2 = res2 + a2[i] - a2[i + 1];
			}else
			{
				res2 += a2[i];
			}
		}
		printf(" %d", res2);
	}
	if(a3 == 0)
	{
		printf(" N");
	}else
	{
		printf(" %d", a3);
	}
	if(a4N == 0)
	{
		printf(" N");
	}else
	{
		float res4 = (float)a4 / a4N;
		printf(" %.1f", res4);
	}
	if(a5_set.size() == 0)
	{
		printf(" N");
	}else
	{
		set<int>::reverse_iterator it = a5_set.rbegin();
		printf(" %d", *it);
	}
	system("pause");
	return 0;
}