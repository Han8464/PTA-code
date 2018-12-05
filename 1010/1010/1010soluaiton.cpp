#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int main()
{
	char n1[11];
	char n2[11];
	int tag, radix;
	scanf("%s%s", &n1, &n2);
	scanf("%d%d", &tag, &radix);
	int a1[11], a2[11];
	for(int i = 0; i < strlen(n1); i++)
	{
		if(n1[i] >= '0' && n1[i] <= '9')
		{
			a1[i] = n1[i] - '0';
		}else
		{
			a1[i] = n1[i] - '0' - 39;
		}
	}
	for(int i = 0; i < strlen(n2); i++)
	{
		if(n2[i] >= '0' && n2[i] <= '9')
		{
			a2[i] = n2[i] - '0';
		}else
		{
			a2[i] = n2[i] - '0' - 39;
		}
	}

	int s1 = 0, s2 = 0;
	if(tag == 2)
	{
		int j = 0;
		for(int i = strlen(n2) - 1; i >= 0; i--)
		{
			s2 += (pow((double)radix, j) * a2[i]);
			j++;
		}

		int n1_max = a1[0];
		for(int i = 0; i < strlen(n1); i++)
		{
			if((a1[i]) > n1_max)
			{
				n1_max = (a1[i]);
			}
		}
		n1_max ++;
		while(s1 != s2)
		{
			int k = 0;
			for(int i = strlen(n1) - 1; i >= 0; i--)
			{
				s1 += (pow((double)n1_max, k) * (a1[i]));
				k++;
			}
			if(s1 > s2)
			{
				printf("Impossible");
				system("pause");
				return 0;
			}else if(s1 < s2)
			{
				n1_max ++;
			}else if(s2 == s1)
			{
				printf("%d", n1_max);
				system("pause");
				return 0;
			}
		}

	}else
	{
		int j = 0;
		for(int i = strlen(n1) - 1; i >= 0; i--)
		{
			s1 += (pow((double)radix, j) * a1[i]);
			j++;
		}

		int n2_max = a2[0];
		for(int i = 0; i < strlen(n2); i++)
		{
			if((a2[i]) > n2_max)
			{
				n2_max = (a2[i]);
			}
		}
		n2_max ++;
		while(s2 != s1)
		{
			int k = 0;
			for(int i = strlen(n2) - 1; i >= 0; i--)
			{
				s2 += (pow((double)n2_max, k) * (a2[i]));
				k++;
			}
			if(s2 > s1)
			{
				printf("Impossible");
				system("pause");
				return 0;
			}else if(s2 < s1)
			{
				n2_max ++;
			}else if(s2 == s1)
			{
				printf("%d", n2_max);
				system("pause");
				return 0;
			}
		}
	}
}