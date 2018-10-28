#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	string str1;
	getline(cin, str1);
	int longest = str1.size();
	for(int i = 0; i < n - 1; i++)
	{
		string str2;
		getline(cin, str2);
		int str1_len = str1.size() - 1;
		int str2_len = str2.size() - 1;
		int k = 0;
		while( k < longest && str1[str1_len] == str2[str2_len])
		{
			str1_len --;
			str2_len --;
			k++;
		}
		longest = k;
		str1 = str2;
	}
	if(longest == 0)
	{
		printf("nai\n");
	}else
	{
		int n = str1.size();
		string result = "";
		for(int j = n - longest; j < n; j++)
		{
			result += str1[j];
		}
		cout<<result<<endl;
	}
	system("pause");
	return 0;

}