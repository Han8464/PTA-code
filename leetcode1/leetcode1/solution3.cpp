/*
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
		vector<Interval> answer;
		int size = A.size() > B.size() ? B.size() : A.size();
		int b = 0;
		int a = 0;
        if(size == 0)
			return answer;
		while(a < A.size() && b < B.size())
		{
			if(A[a].start > B[b].end)
			{
				b++;
			}else if(A[a].end < B[b].start)
			{
				a++;
			}else if(A[a].start <= B[b].start)
			{
				if(A[a].end <= B[b].end)
				{
					Interval tmp;
					tmp.start = B[b].start;
					tmp.end = A[a].end;
					answer.push_back(tmp);
					a++;
				}else
				{
					Interval tmp;
					tmp.start = B[b].start;
                    tmp.end = B[b].end;
					answer.push_back(tmp);
					b++;
				}
			}else if(A[a].start >= B[b].start)
			{
				if(A[a].end >= B[b].end)
				{
					Interval tmp;
					tmp.start = A[a].start;
					tmp.end = B[b].end;
					answer.push_back(tmp);
					b++;
				}else
				{
					Interval tmp;
					tmp.start = A[a].start;
                    tmp.end = A[a].end;
                    answer.push_back(tmp);
					a++;
				}
			}
		}
		return answer;
    }
};
*/