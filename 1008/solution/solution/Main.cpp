#include <cstdio>
#include <cstdlib>
int main()
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	int n = 0;
	int uOrd;
	int tmp;
	for (int i = 0; i < N;i++)
	{
		scanf("%d",&tmp);
		uOrd = tmp - n;
		if(uOrd > 0)
		{
			sum += (uOrd * 6 + 5);
		}else
		{
			sum += ((-uOrd) * 4 + 5);
		}
		n = tmp;
	}
	printf ("%d", sum);
	system("pause");
	return 0;
}