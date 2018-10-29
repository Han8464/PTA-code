#include <cstdio>
#include <cstdlib>
int sum[10010][10010] = {0};
int main()
{
	int k;
	int seq[10010];
	scanf("%d", &k);
	int neg_num = 0;
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &seq[i]);
		if(seq[i] < 0)
		{
			neg_num ++;
		}
	}
	if(neg_num == k)
	{
		printf("0 %d %d", seq[0], seq[k - 1]);
		system("pause");
		return 0;
	}
	int max = seq[0];
	int s, e, s_i, e_j;
	s = e = seq[0];
	for(int i = 0; i < k; i++)
	{
		sum[i][i] = seq[i];
		if(sum[i][i] > max)
		{
			max = sum[i][i];
			s = seq[i];
			e = seq[i];
		}
		for(int j = i + 1; j < k; j++)
		{
			sum[i][j] = sum[i][j - 1] + seq[j];
			if(sum[i][j] > max)
			{
				max = sum[i][j];
				s = seq[i];
				e = seq[j];
			}
		}
	}
	printf("%d %d %d", max, s, e);
	system("pause");
	return 0;
}