#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	multiset<int> data;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		data.insert(tmp);
	}
	int k = n / 2;
	int s1 = 0;
	int s2 = 0;
	int x = 0;
	multiset<int> ::iterator it = data.begin();
	for(;it != data.end(); it++)
	{
		if(x < k)
		{
			s1 += *it;
			x++;
		}else
		{
			s2 += *it;
			x++;
		}
	}
	printf("%d %d", n % 2, s2 - s1);
	system("pause");
	return 0;
}