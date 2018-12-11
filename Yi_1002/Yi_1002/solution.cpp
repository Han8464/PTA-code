#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	string s;
	cin>>s;
	int sum = 0;
	for(int i = 0; i < s.size(); i++)
	{
		sum += (s[i] - '0');
	}
	int digit[1010];
	int s_digit = 0;
	while(sum > 0)
	{
		digit[s_digit] = (sum % 10);
		sum = sum / 10;
		s_digit ++;
	}
	for(int i = s_digit - 1; i > 0; i --)
	{
		cout<< pinyin[digit[i]]<<" ";
	}
	cout<<pinyin[digit[0]];
	system("pause");
	return 0;
}