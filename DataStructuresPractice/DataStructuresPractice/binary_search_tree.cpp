#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root);
	bool Valid(TreeNode* root, int* min, int* max);
};

bool Solution::isValidBST(TreeNode* root)
{
	int min, max;
	return Valid(root, &min, &max);
}

bool Solution::Valid(TreeNode* root, int* min, int* max)
{
	if(root == NULL)
	{
		return true;
	}
	int l_min, l_max, r_min, r_max;
	if(root->left != NULL)
	{
		if(Valid(root->left, &l_min, &l_max))
		{
			if(l_max >= root->val)
			{
				return false;
			}
		}else
		{
			return false;
		}
	}else
	{
		l_min = root->val;
	}

	if(root->right != NULL)
	{
		if(!Valid(root->right, &r_min, &r_max))
		{
			return false;
		}else
		{
			if(r_min <= root->val)
			{
				return false;
			}
		}
	}else
	{
		r_max = root->val;
	}
	*min = l_min;
	*max = r_max;
	return true;
}



int main()
{
	TreeNode* root = new TreeNode(5);
	TreeNode* a1 = new TreeNode(1);
	TreeNode* a2 = new TreeNode(4);
	TreeNode* a3 = new TreeNode(3);
	TreeNode* a4 = new TreeNode(6);
	root->left = a1;
	root->right = a2;
	a1->left = NULL;
	a1->right = NULL;
	a2->left = a3;
	a2->right = a4;
	a3->left = NULL;
	a3->right = NULL;
	a4->left = a4->right = NULL;
	Solution* s = new Solution();
	cout<<s->isValidBST(root)<<endl;
	system("pause");
	return 0;
}