#include <cstdio>
#include <cstdlib>

int main()
{
	int d, n;
	scanf("%d%d", &d, &n);
	if(n == 1)
	{
		printf("%d", d);
		return 0;
	}
	int i = 2;
	char *tmp;
 	tmp = (char *)malloc(sizeof(char) * 100000);
	char *res;
	res = (char*)malloc(sizeof(char) * 100000);
	tmp[0] = d + '0';
	int len_t = 1;
	while (i <= n)
	{
		int len_r = 0;
		for(int j = 0; j < len_t;j++)
		{
			res[len_r] = tmp[j];
			len_r ++;
			int total = 1;
			for(int k = j + 1; k < len_t; k++)
			{
				if(tmp[k] != tmp[k - 1])
					break;
				total ++;
			}
			res[len_r] = total + '0';
			len_r ++;
			j = j + total - 1;
		}
		char *t = tmp;
		tmp = res;
		res = t;
		len_t = len_r;
		if (i == n)
		{
			tmp[len_t + 1] = '\0';
			printf("%s", tmp);
			
		}
			
		i++;
	}
	system("pause");
	return 0;
}