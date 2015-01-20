#include <iostream>
#include<vector>
#include<string>
#include<sstream>
using std::cout;
using std::endl;
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		//if empty string
		if (inorder.size() <= 0) return NULL;
	
		TreeNode * root = buildChildren(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
		return root;
		


	}
	TreeNode * buildChildren(vector<int> &inorder, int in_begin, int in_end, vector<int> &postorder, int post_begin, int post_end)
	{
		int val = postorder[post_end];
		int left_num, right_num;
		int i;

		TreeNode * root = new TreeNode(val);
		for (i = in_begin; inorder[i] != val; i++);

		left_num = i-in_begin;  
		right_num = in_end - i;
			

		if (left_num > 0)
		{
			root->left = buildChildren(inorder, in_begin, in_begin+left_num-1, postorder, post_begin, post_begin+left_num-1);
		}
		if (right_num > 0)
		{
			root->right = buildChildren(inorder, in_end-right_num+1, in_end, postorder, post_begin+left_num, post_end-1);
		}
		return root;
	}

};

int main()
{
	vector<int> inorder;
	vector<int>postorder;

	inorder.push_back(2);
	postorder.push_back(2);

	inorder.push_back(1);
	postorder.push_back(1);
	Solution s;
	s.buildTree(inorder, postorder);
	return 0;
}
