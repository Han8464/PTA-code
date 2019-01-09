#include <cstdio>
#include <cstdlib>
#include <cmath>

int main()
{
	int a, da, b, db;
	scanf("%d%d%d%d", &a, &da, &b, &db);
	int n_a = 0, n_b = 0;
	while(a > 0)
	{
		int tmp1 = a % 10;
		if(tmp1 == da)
		{
			n_a ++;
		}
		a = a / 10;
	}
	while(b > 0)
	{
		int tmp2 = b % 10;
		if(tmp2 == db)
		{
			n_b ++;
		}
		b = b / 10;
	}
	int pa = 0, pb = 0;
	while(n_a != 0)
	{
		pa += (pow(10.0, n_a - 1) * da);
		n_a --;
	}
	while(n_b != 0)
	{
		pb += (pow(10.0, n_b - 1) * db);
		n_b --;
	}

	printf("%d", pa + pb);
	system("pause");
	return 0;

}