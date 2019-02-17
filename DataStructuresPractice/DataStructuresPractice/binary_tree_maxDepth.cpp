#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
/*
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    int maxDepth(TreeNode* root);
	int getDepth(TreeNode* root, int depth, int max);
};

int Solution::maxDepth(TreeNode* root)
{
	int depth = 0;
	int max = 0;
	int n = getDepth(root, depth, max);
	return n;
}

int Solution::getDepth(TreeNode* root, int depth, int max)
{
	depth++;
	TreeNode* cur = new TreeNode(0);
	if(root != NULL && root->left != NULL)
	{
		cur = root->left;
		max = getDepth(cur, depth, max);
	}
	if(root != NULL && root->right != NULL)
	{
		cur = root->right;
		max = getDepth(cur, depth, max);
	}
	if(root != NULL && root->left == NULL && root->right == NULL)
	{
		if(depth > max)
		{
			max = depth;
		}
	}
	return max;
}
int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* a1 = new TreeNode(9);
	TreeNode* a2 = new TreeNode(20);
	TreeNode* a3 = new TreeNode(15);
	TreeNode* a4 = new TreeNode(7);
	root->left = a1;
	root->right = a2;
	a1->left = NULL;
	a1->right = NULL;
	a2->left = a3;
	a2->right = a4;
	a3->left = a3->right = NULL;
	a4->left = a4->right = NULL;

	Solution* s = new Solution();
	int max = s->maxDepth(root);
	cout<<max<<endl;
	system("pause");
	return 0;


}*/