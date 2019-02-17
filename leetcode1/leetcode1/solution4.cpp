#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
typedef struct Node{
	int x, y, val;
}Node;
class Solution {
public:
	Node nodes[1010];
	int len;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>>answer;
        if(root == NULL)
            return answer;
		len = 0;
		traversal(root, 0, 0);
		sort(nodes, nodes + len, comp);
        for(int i = 0; i < len; i++)
		{
			cout<<nodes[i].x<<" "<<nodes[i].y<<" "<<nodes[i].val<<endl;
		}
		int i = 0;
		while(i < len)
		{
            cout<<i<<endl;
			vector<int> tmp;
			tmp.push_back(nodes[i].val);
			int j = i + 1;
			int count = 1;
			while(nodes[j].x == nodes[i].x && j < len)
			{
				tmp.push_back(nodes[j].val);
                j++;
				count++;
			}
			answer.push_back(tmp);
			i += count;
		}
        return answer;
    }
    static int comp(Node a, Node b){
		if(a.x == b.x){
			if( a.y == b.y){
				return a.val < b.val;
			}else
				return a.y > b.y;
		}else
			return a.x < b.x;
	}
	void traversal(TreeNode* root, int x, int y){
		if(root != NULL)
		{
			Node n;
			n.val = root->val;
			n.x = x;
			n.y = y;
			nodes[len] = n;
			len ++;
		}
		if(root->left != NULL)
		{
			traversal(root->left, x - 1, y - 1);
		}
		if(root->right != NULL)
		{
			traversal(root->right, x + 1, y - 1);
		}
	}

	
};