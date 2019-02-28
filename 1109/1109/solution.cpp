#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
using namespace std;
typedef struct P
{
	string name; 
	int	h;
}P;
vector<P*> v;
bool comp(P* p1, P* p2)
{
	if(p1->h == p2->h)
		return p1->name < p2->name;
	return p1->h > p2->h;
}
int main()
{
	int n, k;
	scanf("%d%d",&n, &k);

	for(int i = 0; i < n; i++)
	{
		P* person = new P;
		cin>>person->name;
		scanf("%d", &person->h);
		v.push_back(person);
	}
	sort(v.begin(), v.end(), comp);
	int num = (n - ((n / k) * k)) + n / k;
	int x = 0;
	while(x < v.size())
	{
		vector<string> q(num + 1);
		int b;
		if(x + num - 1 >= v.size())
		{
			b = v.size() - 1;
		}else
		{
			b = x + num - 1;
		}
		int t1 = num/2 + 1;
		q[t1] = v[x]->name;
		int tmp = 1;
		for(int i = x + 1; i <= b; i = i + 2)
		{
			q[num / 2 + 1 - tmp] = v[i]->name;
			if(i + 1 <= b)
			{
				q[num / 2 + 1 + tmp] = v[i + 1]->name; 
			}
			tmp++;
		}
		for(int j = 1; j <= num; j++)
		{
			if(j == num)
			{
				cout<<q[j];
			}else
			{
				cout<<q[j]<<" ";
			}
		}
		printf("\n");
		x += num;
		num = n / k;
	}
	system("pause");
	return 0;
}
