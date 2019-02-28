#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
int pre[10010];
float estate[10010];
float area[10010];
map<int, bool> id_visit;
int Findroot(int a)
{
	int x = a;
	while(pre[a] != a)
	{
		a = pre[a];
	}
	while(x != a)
	{
		int tmp = pre[x];
		pre[x] = a;
		x = tmp;
	}
	return a;
}
void Union(int a, int b)
{
	int fa = Findroot(a);
	int fb = Findroot(b);
	if(fa < fb)
	{
		pre[fb] = fa;
	}else
	{
		pre[fa] = fb;
	}
}
int main()
{
	for(int i = 0; i < 10010; i++)
	{
		pre[i] = i;
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		int id, fa, ma, k;
		scanf("%d%d%d%d", &id, &fa, &ma, &k);
		id_visit[id] = false;
		if(fa != -1)
		{
			Union(id, fa);
			id_visit[fa] = false;
		}
		if(ma != -1)
		{
			Union(id, ma);
			id_visit[ma] = false;
		}
		for(int j = 0; j < k; j++)
		{
			int ch;
			scanf("%d", &ch);
			Union(id, ch);
			id_visit[ch] = false;
		}
		float es, ar;
		scanf("%f%f", &es, &ar);
		estate[id] = es;
		area[id] = ar;
	}
	

	map<int, bool>::iterator it = id_visit.begin();
	for(; it != id_visit.end(); it++)
	{
		Findroot(it->first);
		printf("%d %d\n", it->first, pre[it->first]);
	}
	system("pause");
	return 0;

	
}