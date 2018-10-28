#include <cstdio>
#include <cstdlib>
#include <cmath>
char sci[10010];
int main()
{                                                                  
	scanf("%s", sci);
	int i = 0;
	int j = 0;
	int flag;
	int num_0 = 0;;
	while(sci[i] != 'E')
	{
		if(i > 2)
		{
			j ++;
		} 
		if(sci[i + 1] == 'E')
		{
			if(sci[i + 2] == '-')
			{
				flag = 0;
			}else 
			{
				flag = 1;
			}
			int k = i + 3;
			int len = 0;
			while(sci[k + len] != '\0')
			{
				len ++;
			}
			int tmp  = len - 1;
			for(int m = 0; m < len; m++)
			{
				num_0 += ((sci[k + m] - '0') * pow(10.0, tmp));
				tmp--;
			}
		}
		i++;
	}
	if(sci[0] == '-')
	{
		printf("-");
	}
	if(flag == 0)
	{
		printf("0.");
		for(int m = 0; m < num_0 - 1; m++)
		{
			printf("0");
		}
		printf("%c", sci[1]);
		for(int m = 3; m < i; m++)
		{
			printf("%c", sci[m]);
		}
	}else
	{
		printf("%c", sci[1]);
		if(num_0 >= j)
		{
			for(int m = 3; m < j + 3; m++)
			{
				printf("%c", sci[m]);
			}
			for(int m = 0; m < (num_0 - j); m++)
			{
				printf("0");
			}
		}else
		{
			for(int m = 3; m < num_0 + 3; m++)
			{
				printf("%c", sci[m]);
			}
			printf(".");
			for(int m = 3 + num_0; m < j + 3; m++)
			{
				printf("%c", sci[m]);
			}
		}


	}
	system("pause");
	return 0;

}