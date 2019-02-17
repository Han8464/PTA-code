/*
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		vector<int> answer;
		int val;
		int index;
		for(int i = 0; i < A.size(); i ++)
		{
			val = queries[i][0];
			index = queries[i][1];
			A[index] += val;
			int tmp = 0;
			for(int i = 0; i < A.size(); i++)
			{
				if(A[i] % 2 == 0 && A[i] != 0)
				{
					tmp += A[i];
				}
			}
			answer.push_back(tmp);
		}
		return answer;
    }
};*/