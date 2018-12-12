#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct Info
{
	int id;
	int de;
	int cai;
	int total;
}Info;
vector<Info> infos1, infos2, infos3, infos4;
bool com(Info info1, Info info2)
{
	if(info1.total > info2.total)
		return true;
	else if(info1.total == info2.total)
	{
		if(info1.de > info2.de)
			return true;
		else if(info1.de ==info2.de)
		{
			if(info1.id < info2.id)
				return true;
		}
	}
	return false;
}
int main()
{ 
	int n, L, H;
	scanf("%d%d%d", &n, &L, &H);
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		Info info;
		scanf("%d%d%d", &info.id, &info.de, &info.cai);
		info.total = info.de + info.cai;
		if(info.de >= L && info.cai >= L)
		{
			sum++;
			if(info.de >=H && info.cai>=H)
				infos1.push_back(info);	
			else if(info.de >=H && info.cai<H )
				infos2.push_back(info);
			else if(info.de <H && info.cai<H  && info.de>=info.cai)
				infos3.push_back(info);
			else 
				infos4.push_back(info);
		}
	}
	sort(infos1.begin(), infos1.end(), com);
	sort(infos2.begin(), infos2.end(), com);
	sort(infos3.begin(), infos3.end(), com);
	sort(infos4.begin(), infos4.end(), com);

	printf("%d\n", sum);
	
 
	vector<Info>::iterator itr;
	for(itr=infos1.begin();itr!=infos1.end();itr++)
		printf("%d %d %d\n",itr->id,itr->de,itr->cai);
	for(itr=infos2.begin();itr!=infos2.end();itr++)
		printf("%d %d %d\n",itr->id,itr->de,itr->cai);
	for(itr=infos3.begin();itr!=infos3.end();itr++)
		printf("%d %d %d\n",itr->id,itr->de,itr->cai);
	for(itr=infos4.begin();itr!=infos4.end();itr++)
		printf("%d %d %d\n",itr->id,itr->de,itr->cai);

	system("pause");
	return 0;
}