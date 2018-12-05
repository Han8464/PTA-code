#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int test()
{
	vector<vector<int>> vec_out;
	vector<int> vec1;
	vector<int> vec2;
	vec1.push_back(1);
	vec1.push_back(2);
	vec2.push_back(3);
	vec2.push_back(4);
	vec_out.push_back(vec1);
	vec_out.push_back(vec2);


	for (vector<int>::reverse_iterator iter = vec1.rbegin(); iter != vec1.rend(); iter++)
	{
		printf("%d\n", *iter);
	}
	system("pause");
	return 0;
}