#include <cstdio>
#include <cstdlib>

int num[16777218] = {0};
int color[480005];
int main()
{
	int n, m;
	scanf("%d%d",&m,&n);
	int k = m * n;
	for(int i = 0; i < k;i ++)
	{
		int tmp;
		scanf("%d",&tmp);
		color[i] = tmp;
		num[tmp] ++;
	}
	int domin = color[0];
	for(int i = 1; i < k; i++)
	{
		if(num[color[i]] > num[domin])
			domin = color[i];
	}
	printf("%d",domin);
	system("pause");
	return 0;

}