#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string word[100];
	int n = 0;
	int last = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == ' ')
		{
			word[n] = s.substr(last, i - last);
			last = i + 1;
			n++;
		}else if(i == s.size() - 1)
		{
			word[n] = s.substr(last, i - last + 1);
			n++;
		}
	}
	n--;
	for(int i = n; i > 0; i--)
	{
		cout<<word[i]<<" ";
	}
	cout<<word[0];
	system("pause");
	return 0;
}