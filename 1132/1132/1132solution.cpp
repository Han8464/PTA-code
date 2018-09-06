#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int n,z;
	scanf("%d",&n);
	string result[22];
	for(int i = 0; i < n; i++){
		int n1[20];
		scanf("%d", &z);
		int tmp = z;
		int len = 0;
		while(tmp > 0)
		{
			n1[len] = tmp % 10;
			tmp = tmp / 10;
			len ++;
		}
		int k = len / 2;
		int a = 0;
		for(int j = 0; j < k; j++)
		{
			a += (n1[j] * (int)pow(10.0, j));
		}
		int b = 0;
		int exp = 0;
		for(int j = k; j < len; j++)
		{
			b += (n1[j] * (int)pow(10.0, exp));
			exp ++;
		}
		
		if(a != 0 && b != 0 && z % (a * b) == 0)
		{
			result[i] = "Yes";
		}else
		{
			result[i] = "No";
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout<<result[i]<<endl;
	}
	system("pause");
	return 0;
}