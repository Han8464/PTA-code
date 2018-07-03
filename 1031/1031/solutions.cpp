#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len = s.length();
	int n1 = (len + 2)/3;
	int i = 0;
	int tmp = len;
	while(tmp > 0)
	{
		int n2 = len - n1 - n1;
		if(i < n1 - 1)
		{
			printf("%c",s[i]);
			while(n2 > 0)
			{
				printf(" ");
				n2 --;
			}
			printf("%c\n",s[len - 1 - i]);
		}else if(i <= (len - n1))
		{
			printf("%c",s[i]);
		}
		tmp --;
		i ++;
	}
	system("pause");
	return 0;
}