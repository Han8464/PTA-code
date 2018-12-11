#include <cstdio>
#include <cstdlib>
int num[110];
void reverse(int m, int n)
{
	for(int i = m; i <= (m + n) / 2; i++)
	{
		int tmp = num[i];
		num[i] = num[m + n - i];
		num[m + n - i] = tmp;
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	m
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	reverse(0, n - m -1);
	reverse(n - m, n - 1);
	reverse(0, n-1);
	for(int i = 0; i < n; i++)
	{
		printf("%d%s", num[i], (i - n + 1)?" ":"\n");
	}
	system("pause");
	return 0;
}