#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string.h>

using namespace std;
int main()
{
	char *s;
	s = new char[20];
	scanf("%s", s);
	int len = strlen(s);
	int origin[20];
	int doubled[21];
	for(int i = 0; i < len; i++)
	{
		origin[i] = *(s+i) - 48;
	}
	int sig = 0;
	int length_d = 0;
	int length_o = len - 1;
	while(length_d < len)
	{
		int tmp = origin[length_o] * 2 + sig;
		if (tmp >= 10) {
			doubled[length_d] = tmp - 10;
			sig = 1;
		} else {
			doubled[length_d] = tmp;
			sig = 0;
		}
		length_d ++;
		length_o --;
	}
	if(sig == 1)
	{
		doubled[length_d] = 1;
	}else
	{
		length_d -= 1;
	}
	char double_n[20];

	int i = 0;
	while(length_d >= 0)
	{
		char tmp = doubled[length_d] + '0';
		double_n[i] = tmp;
		i++;
		length_d --;
	}
	double_n[i] = '\0';
	sort(origin,origin + len);
	sort(doubled,doubled + len);
	for(int i = 0;i < len;i++)
	{
		if(doubled[i] != origin[i])
		{
			printf("No\n");
			printf("%s",double_n);
			return 0;
		}
	}
	printf("Yes\n");
	printf("%s",double_n);
	return 0;
}