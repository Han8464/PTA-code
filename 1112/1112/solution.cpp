#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;
int main()
{
	int k;
	scanf("%d", &k);               
	char s[10010];
	scanf("%s", s);
	int i = 1;
	int x = 1;
	set<char> normal;
	while(s[i] != '\0')
	{
		if(s[i] == s[i - 1])
		{
			x++;
		}else
		{
			if(x % k != 0)
			{
				normal.insert(s[i - 1]);
			}
			x = 1;
		}
		i++;
		
		if(s[i] == '\0')
		{
			if(x % k != 0)
				normal.insert(s[i - 1]);
		}
	}
	int y = 0;
	set<char> isfind;
	while(s[y] != '\0')
	{
		if(normal.find(s[y]) == normal.end() && isfind.find(s[y]) == isfind.end())
		{
			printf("%c", s[y]);
			isfind.insert(s[y]);
		}
		y++;
	}
	printf("\n");
	y = 0;
	while(s[y] != '\0')
	{
		if(normal.find(s[y]) == normal.end())
		{
			printf("%c", s[y]);
			y += k;
		}else
		{
			printf("%+c", s[y]);
			y++;
		}
	}
	printf("\n");
	system("pause");
	return 0;

}