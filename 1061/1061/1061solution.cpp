#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char day[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	
	char i1[66], i2[66], i3[66], i4[66];
//	printf("%d %d %d %d", 'N', 'G', 'A', 'Z');
	
	scanf("%s%s%s%s", i1, i2, i3, i4);
	int flag = 1;
	for(int i = 0; i < strlen(i1); i++)
	{
		if(i1[i] >= 'A' && i1[i] <= 'G')
		{
			if(i2[i] == i1[i] && flag == 1)
			{
				printf("%s ", day[i1[i] - 'A']);
				flag = 2;
				continue;
			}
		}
		if((i1[i] >= 'A' && i1[i] <= 'N') && flag == 2)
		{
			if(i2[i] == i1[i])
			{
				printf("%d:", i1[i] - 'A' + 10);
				break;
			}

		}else if(i1[i] >= '0' && i1[i] <= '9' && flag == 2)
		{
			if(i2[i] == i1[i])
			{
				printf("0%d:", i1[i] - '0');
				break;
			}
		}
	}

	int  min = 0;
	while (min < strlen(i3))
	{
		if(((i3[min] >= 'a' && i3[min] <= 'z') || (i3[min] >= 'A' && i3[min] <= 'Z'))
			&& i3[min] == i4[min])
		{
			if(min <= 9)
			{
				printf("0%d", min);
			}else
			{
				printf("%d", min);
			}
			break;
		}
		min ++;
	}
	system("pause");
	return 0;
}

