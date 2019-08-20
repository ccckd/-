#include<iostream>
#include<vector>
using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q)
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p ,q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left == nullptr && right == nullptr)
			return nullptr;
		if (left != nullptr && right != nullptr)
			return root;
		return left == nullptr ? right : left;
		

	}

	


};

int main() {

	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *a = new TreeNode(1);
	a->left = b;
	a->right = c;
	Solution s = Solution();
	TreeNode *res = s.lowestCommonAncestor(a, b, c);
	cout << res->val << endl;
}