#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct node
{
	int line,s,e;
	node(int xl,int xs,int xe):line(xl),s(xs),e(xe){}
};
int searchLine[10000][10000];//�ж�����վ������������
int n,q,minstation,mintransfer;//�߸����������������С��վ�㣬��С�Ļ���
vector<vector<int>> v(10000);//ͼ���ڽӱ�
vector<node> ans,recp;//���ս��·�����м��¼·��
bool visit[10000];//�ж��Ƿ��Ѿ���������
void subwayMap(int head,int cur,int end,int staioncnt,vector<node> &recp,int pre)
{
	if(cur==end&&(staioncnt<minstation||(staioncnt==minstation&&mintransfer>(int)recp.size()+1)))
	{
		minstation=staioncnt;
		ans=recp;
		ans.push_back(node(searchLine[pre][end],head,end));
		mintransfer=ans.size();
		return;
	}
	visit[cur]=1;
	for(auto next:v[cur])
	{
		if(visit[next]) continue;
		if(pre!=cur&&searchLine[pre][cur]!=searchLine[cur][next])//��·��ͬ��curΪ���˽ڵ�
		{
			recp.push_back(node(searchLine[pre][cur],head,cur));//�ռ���һ����·��Ϣ�������ߣ���վ��βվ
			subwayMap(cur,next,end,staioncnt+1,recp,cur);
			recp.pop_back();
		}
		else subwayMap(head,next,end,staioncnt+1,recp,cur);//��·��ͬ����վ����;
	}
	visit[cur]=0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int k,idx,pre;
		scanf("%d %d",&k,&pre);
		for(int j=0;j<k-1;++j)
		{
			cin>>idx;
			searchLine[pre][idx]=searchLine[idx][pre]=i;//�������ڽڵ����·
			v[pre].push_back(idx);
			v[idx].push_back(pre);
			pre=idx;
		}
	}
	cin>>q;
	while(q--)
	{
		int s,e;
		scanf("%d %d",&s,&e);
		minstation=mintransfer=0x7fffffff;
		subwayMap(s,s,e,0,recp,s);
		printf("%d\n",minstation);
		for(auto x:ans) printf("Take Line#%d from %04d to %04d.\n",x.line,x.s,x.e);
	}
	return 0;
}