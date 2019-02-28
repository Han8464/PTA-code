#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int pre_hobby[1010] = {0};
int pre_person[1010];
int visit[1010] = {0};

bool cmp(int a,int b){
	return a>b;
}

int findf(int a)
{
	int x = a;
	while(pre_person[a] != a)
	{
		a = pre_person[a];
	}
	while(x != a)
	{
		int tmp = pre_person[x];
		pre_person[x] = a;
		x = tmp;
	}
	return a;
}

void Union(int a, int b)
{
	int fa = findf(a);
	int fb = findf(b);
	if(fa < fb)
	{
		pre_person[fb] = fa;
	}else if(fa > fb)
	{
		pre_person[fa] = fb;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 1010; i++)
	{
		pre_person[i] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d:", &k);
		for(int j = 0; j < k; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if(pre_hobby[tmp] == 0)
			{
				pre_hobby[tmp] = i;
			}
			Union(i, pre_hobby[tmp]);

		}
	}
	int isRoot[1010] = {0};
	for(int i = 1; i <= n; i++)
	{
		isRoot[findf(i)]++;
	}

	int ans=0;
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0){
			ans++;
		}
	}
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i=1;i<=ans;i++){
		printf("%d",isRoot[i]);
		if(i<ans)printf(" ");
	}
	system("pause");
	return 0;
}