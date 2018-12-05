#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;
	m[0] = 1;
	m[2] = 3;

	if(m.find(0) == m.end())
	{
		printf("Not exist");
	}else
	{
		printf("Exists");
	}
	system("pause");
	return 0;
}