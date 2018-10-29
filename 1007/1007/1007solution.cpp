#include <cstdio>
#include <cstdlib>
int main()
{
	int k;
	int seq[10010];
	scanf("%d", &k);
	int tmp = 0;
	int max = -1;
	int left = 0, right = k - 1,tmpleft = 0;
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &seq[i]);
		tmp += seq[i];
		if(tmp < 0)
		{
			tmp = 0;
			tmpleft = i + 1;
		}else if(tmp > max)
		{
			max = tmp;
			right = i;
			left = tmpleft;
		}
	}
	if(max < 0) max = 0;
	printf("%d %d %d", max, seq[left], seq[right]);
	system("pause");
	return 0;
}