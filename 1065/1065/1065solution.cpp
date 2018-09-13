#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	long long  a, b, c, num;
	int t;
	string result[20];
	cin>>t;
	
	for(int i = 0; i < t; i ++)
	{
		cin>>a>>b>>c;
		num = a + b;
		if(a > 0 && b > 0 && num < 0)
		{
			printf("Case #%d: true\n", i + 1);
		}else if(a < 0 && b < 0 && num >= 0)
		{
			printf("Case #%d: false\n", i + 1);
		}else if(num > c)
		{
			printf("Case #%d: true\n", i + 1);
		}else
		{
			printf("Case #%d: false\n", i + 1);
		}
	}
	system("pause");
	return 0;
}