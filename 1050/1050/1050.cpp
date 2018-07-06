#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	char s1[10005];
	char s2[10005];
	bool asc[130] = {0};
	cin.getline(s1,10005);
	cin.getline(s2,10005);
	int j = 0;
	while(s2[j] != '\0')
	{
		asc[s2[j]] = 1;
		j++;
	}
	int i = 0;
	while(s1[i] != '\0')
	{
		if(asc[s1[i]] == 0)
		{
			printf("%c",s1[i]);
		}
		i++;
	}
	system("pause");
	return 0;
}