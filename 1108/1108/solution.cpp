#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int numoflegal = 0;
	float sum = 0;
	for(int i = 0; i < n; i++)
	{
		char x[1010];
		scanf("%s", x);
		float number = 0;
		bool islegal = true;
		int dot_pos = -1;
		int cnt_deci = 0;
		for(int j = 0; j < strlen(x); j++)
		{
			if(x[j] != '.' && x[j] != '-' &&( x[j] < '0' || x[j] > '9'))
			{
				islegal = false;
				break;
			}
			if(x[j] == '.')
			{
				if(dot_pos == -1)
				{
					dot_pos = j;
				}else
				{
					islegal = false;
					break;
				}
			}
			if(x[j] == '-' && j != 0)
			{
				islegal = false;
				break;
			}
			if(x[j] > '0' && x[j] < '9' && dot_pos != -1)
			{
				cnt_deci ++;
				if(cnt_deci > 2)
				{
					islegal = false;
					break;
				}
			}
		}
		if(islegal == false)
		{
			printf("ERROR: %s is not a legal number\n", x);
		}else
		{

			float tmp;
			sscanf(x, "%f", &tmp);
			if(tmp >= -1000 && tmp <= 1000)
			{
				numoflegal ++;
				sum += tmp;
			}else
			{
				printf("ERROR: %s is not a legal number\n", x);
			}
			
		}
	}
	if(numoflegal == 1)
	{
		printf("The average of 1 number is %0.2f\n", sum);
	}else if(numoflegal == 0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}else
	{
		printf("The average of %d numbers is %0.2f\n", numoflegal, sum / numoflegal);
	}
	system("pause");
	return 0;
}