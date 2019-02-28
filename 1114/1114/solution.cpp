
/*
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Node
{
	int id;
	float estate, area;
	set<int>neigh_id;
}Node;

typedef struct Result
{
	int id, num;
	float es, ar;
}Result;
vector<Result*> results;
map<int, bool>id_visit;
map<int, Node*>id_add;
vector<int> family;
set<int> had;
float totales = 0;
float totalar = 0;
int comp(Result* r1, Result* r2)
{
	if(r1->ar == r2->ar)
	{
		return r1->id < r2->id;
	}
	return r1->ar > r2->ar;
}

void bfs(int k)
{
	if(k < family.size())
	{
		id_visit[family[k]] = true;
		had.insert(family[k]);
		Node* node = id_add[family[k]];
		if(node->estate >= 0 && node->area >= 0)
		{
			totales += node->estate;
			totalar += node->area;
		}
		set<int> ::iterator it = node->neigh_id.begin();
		for(; it != node->neigh_id.end(); it++)
		{
			if(had.find(*it) == had.end())
			{
				family.push_back(*it);
				had.insert(*it);
			}
		}
		k++;
		bfs(k);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		
		int id, fa, ma, k;
		scanf("%d%d%d%d", &id, &fa, &ma, &k);
		Node* node;
		if(id_add.find(id) != id_add.end())
		{
			node = id_add[id];
		}else
		{
			node = new Node;
			node->id = id;
		}
		if(fa != -1)
		{
			node->neigh_id.insert(fa);
			if(id_add.find(fa) == id_add.end())
			{
				Node* nfa = new Node;
				nfa->id = fa;
				nfa->estate = -1;
				nfa->area = -1;
				nfa->neigh_id.insert(id);
				id_add[fa] = nfa;
				id_visit[fa] = false;
			}
			else
			{
				id_add[fa]->neigh_id.insert(id);
			}
		}

		if(ma != -1)
		{
			node->neigh_id.insert(ma);
			if(id_add.find(ma) == id_add.end())
			{
				Node* nma = new Node;
				nma->id = ma;
				nma->estate = -1;
				nma->area = -1;
				nma->neigh_id.insert(id);
				id_add[ma] = nma;
				id_visit[ma] = false;
			}else
			{
				id_add[ma]->neigh_id.insert(id);
			}
		}
		for(int j = 0; j < k; j++)
		{
			int ch;
			scanf("%d", &ch);
			node->neigh_id.insert(ch);
			if(id_add.find(ch) == id_add.end())
			{
				Node* nch = new Node;
				nch->id = ch;
				nch->estate = -1;
				nch->area = -1;
				nch->neigh_id.insert(id);
				id_add[ch] = nch;
				id_visit[ch] = false;
			}
			else
			{
				id_add[ch]->neigh_id.insert(id);
			}
		}
		float es, ar;
		scanf("%f%f", &es, &ar);
		node->estate = es;
		node->area = ar;
		id_add[node->id] = node;
		id_visit[node->id] = false;
	}
	map<int, Node*>::iterator it = id_add.begin();
	for(; it != id_add.end(); it++)
	{
		if(id_visit[it->first] == false)
		{
			family.push_back(it->first);
			bfs(0);
			int totalnumber = family.size();
			sort(family.begin(), family.end());
			Result* r = new Result;
			r->id = family[0];
			r->num = family.size();
			r->es = totales/totalnumber;
			r->ar = totalar/totalnumber;
			results.push_back(r);
			family.clear();
			totales = 0;
			totalar = 0;
		}

	}

	sort(results.begin(), results.end(), comp);
	printf("%d\n", results.size());
	for(int i = 0; i < results.size(); i++)
	{
		printf("%04d %d %0.3f %0.3f\n", results[i]->id, results[i]->num, results[i]->es, results[i]->ar);
	}

	system("pause");
	return 0;

}
*/