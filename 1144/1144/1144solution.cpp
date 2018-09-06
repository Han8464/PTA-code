#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

int main()
{
	int n;
	scanf ("%d", &n);
	set <int> res;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf ("%d", &tmp);
		if (tmp > 0)
		{
			res.insert(tmp);
		}
	}
	if (*res.begin() == 1)
	{
		int begin = *res.begin();
		while(res.size() > 0)
		{
			res.erase(begin);
			if (* res.begin() == (begin + 1))
			{
				begin = *res.begin();
				res.erase(begin);
			}else
			{
				printf ("%d", begin + 1);
				system("pause");
				return 0;
			}
		}
		printf ("%d", begin + 1);
		system("pause");
		return 0;
	}else
	{
		printf ("%d", 1);
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}