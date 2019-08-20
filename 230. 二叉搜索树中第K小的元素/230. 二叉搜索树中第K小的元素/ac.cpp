#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };


 
class Solution{
public:
	vector<int> vec;
	int kthSmallest(TreeNode* root, int k) {
		m(root, k);
		return vec[k - 1];
	}

	void m(TreeNode *root, int k) {
		if (root == nullptr)
			return;
		if (root->left)
			m(root->left, k);
		if (vec.size() == k)
			return;
		vec.push_back(root->val);
		if (root->right)
			m(root->right, k);
	}
};


