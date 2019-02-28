#include <cstdio>
#include <cstdlib>
int main()
{
	int n;
	scanf("%d", &n);
	double total = 0;
	for(int i = 1; i <= n; i++)
	{
		double x;
		scanf("%lf", &x);
		total += x * i * (n - i + 1);
	}
	printf("%.2f\n", total);
	system("pause");
	return 0;
}
