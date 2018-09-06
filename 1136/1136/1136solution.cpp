#include <cstdio>
#include <cstdlib>
#include <string>

bool judge(char *a)
{
	int len = strlen(a);
	int i = 0;
	int j = len - 1;
	while (i <= j)
	{
		if(a[i] != a[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}


int main()
{
	char n1[1012];
	char n2[1012];
	char n3[1012];
	char* a = n1;
	a[1011] = '\0';
	char* b = n2;
	b[1011] = '\0';
	char* c = n3;
	c[1011] = '\0';
	scanf("%s", a);
	if(strlen(a) == 1 && a[0] - '0' == 0)
	{
		printf("0 is a palindromic number.");
		system("pause");
		return 0;
	}
	int num = 0;
	while(num < 10)
	{
		if(judge(a) == true)
		{
			printf("%s is a palindromic number.", a);
			system("pause");
			return 0;
		}
		int len_a = strlen(a);
		int len_b = len_a;
		b[len_b] = '\0';
		for(int i = 0; i < len_a; i++)
		{
			b[len_b - 1] = a[i];
			len_b--;
		}
		int flag = 0;
		int tmp_c = len_a + 1;
		c[tmp_c] = '\0';
		for(int j = len_a - 1; j >= 0; j--)
		{
			int sum = a[j] + b[j] + flag - '0' - '0';
			if(sum >= 10)
			{

				c[tmp_c - 1] = (sum % 10) + '0';
				flag = (sum - (sum % 10)) / 10;
			}else
			{
				c[tmp_c - 1] = sum + '0';
				flag = 0;
			}
			if(j == 0 && flag != 0)
			{
				tmp_c --;
				c[tmp_c - 1] = flag + '0';
			}else if(j == 0 && flag == 0)
			{

			}
			else
			{
				tmp_c --;
			}
		}
		if (tmp_c == 1)
		{
			printf("%s + %s = %s\n", a, b, c);
		}else
		{
			c = c + 1;
			printf("%s + %s = %s\n", a, b, c);
		}

		char* t = a;
		a = c;
		c = t;
		num ++;
	}
	printf("Not found in 10 iterations.");
	system("pause");
	return 0;
}