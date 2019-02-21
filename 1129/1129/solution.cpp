#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
 
struct node{
	int num, cnt;
	node(int num, int cnt):num(num),cnt(cnt){}
	bool operator < (const node &a)const{ // 重载运算符 
		return cnt != a.cnt ? cnt > a.cnt : num < a.num;
	}
};
set<node> s;
int times[50001], n, k;
int main(){
	scanf("%d%d",&n,&k);
	memset(times, 0, sizeof(times));
	int num;
	for(int i = 0; i < n; i++){
		scanf("%d",&num);
		if(i){
			printf("%d:",num);
			int cnts = 0; // 记录输出的次数 
			for(auto it = s.begin(); cnts < k && it != s.end(); it++){
				printf(" %d",it->num);
				cnts++;
			}
			puts("");
		}		
		auto it = s.find(node(num,times[num])); // 判断set中是否存在 
		if(it != s.end()) s.erase(it); 
		times[num]++; // 更新浏览次数 
		s.insert(node(num,times[num]));
	}
	return 0;
}