#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int m;
	string id;
	int in_h, in_m, in_s;
	int out_h, out_m, out_s;
	vector<int> in_out_time;
	map<string, vector<int>> id_time_map;
	scanf("%d", &m);
	string min_in_id;
	string max_out_id;
	int min = 25, max = -1;
	for(int i = 0; i < m; i++)
	{
		cin>>id;
		scanf("%d:%d:%d", &in_h, &in_m, &in_s);
		scanf("%d:%d:%d", &out_h, &out_m, &out_s);
		id_time_map[id].push_back(in_h);
		id_time_map[id].push_back(in_m);
		id_time_map[id].push_back(in_s);
		id_time_map[id].push_back(out_h);
		id_time_map[id].push_back(out_m);
		id_time_map[id].push_back(out_s);
		if(in_h < min)
		{
			min_in_id = id;
			min = in_h;
		}else if(in_h == min)
		{
			if(in_m < id_time_map[min_in_id][1])
			{
				min_in_id = id;
				min = in_h;
			}else if(in_m == id_time_map[min_in_id][1])
			{
				if(in_s < id_time_map[min_in_id][2])
				{
					min_in_id = id;
					min = in_h;
				}
			}
		}
		if(out_h > max)
		{
			max_out_id = id;
			max = out_h;
		}else if(out_h == max)
		{
			if(out_m > id_time_map[max_out_id][4])
			{
				max_out_id = id;
				max = out_h;
			}else if(out_m == id_time_map[max_out_id][4])
			{
				if(out_s > id_time_map[max_out_id][5])
				{
					max_out_id = id;
					max = out_h;
				}
			}

		}
	}
	cout<<min_in_id<<" "<<max_out_id;
	system("pause");
	return 0;
}