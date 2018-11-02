#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
using namespace std;
int main()
{
	int k1;
	scanf("%d", &k1);
	float ex1[11];
	float co1[11];
	for(int i = 0; i < k1; i++)
	{
		scanf("%f", &ex1[i]);
		scanf("%f", &co1[i]);
	}
	int k2;
	scanf("%d", &k2);
	float ex2[11];
	float co2[11];
	for(int i = 0; i < k2; i++)
	{
		scanf("%f", &ex2[i]);
		scanf("%f", &co2[i]);
	}
	map<float, float>ex_co_map;
	set<float, greater<float>>ex_set;
	for(int i = 0; i < k1; i++)
	{
		for(int j = 0; j < k2; j++)
		{
			float tmp_ex;
			float tmp_co;
			tmp_ex = ex1[i] + ex2[j];
			tmp_co = co1[i] * co2[j];
			if(tmp_co != 0)
			{
				ex_set.insert(tmp_ex);
				if(ex_co_map.find(tmp_ex) == ex_co_map.end())
				{
					ex_co_map[tmp_ex] = tmp_co;
				}else
				{
					tmp_co += ex_co_map[tmp_ex];
					if(tmp_co != 0.0)
					{
						ex_co_map[tmp_ex] = tmp_co;
					}else
					{
						ex_co_map.erase(tmp_ex);
						ex_set.erase(tmp_ex);
					}
				}
			}
		}
	}
	printf("%d", ex_co_map.size());
	set<float, greater<float>>::iterator iter = ex_set.begin();
	for(iter; iter != ex_set.end(); iter++)
	{
		printf(" %.0f ", *iter);
		printf("%.1f", ex_co_map[*iter]);
	}
	system("pause");
	return 0;
}