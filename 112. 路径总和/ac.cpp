
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
	bool loop(TreeNode* root, int now, int sum) {
		if (root == nullptr)
			return false;
		now += root->val;

		if (root->left == nullptr && root->right == nullptr) {
			if (now == sum) {
				return true;
			}
			else {
				return false;
			}
		}

		return loop(root->left, now, sum) || loop(root->right, now, sum);
	}


	bool hasPathSum(TreeNode* root, int sum) {
		return loop(root, 0, sum);
	}
};


int main() {
	Solution s;
	auto a = TreeNode(5);
	auto b = TreeNode(4);
	auto c = TreeNode(8);
	auto d = TreeNode(11);
	auto e = TreeNode(13);
	auto f = TreeNode(4);
	auto g = TreeNode(7);
	auto h = TreeNode(2);
	auto i = TreeNode(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &f;
	c.right = &e;
	d.left = &g;
	d.right = &h;
	f.right = &i;

	auto root = &a;
	s.hasPathSum(root, 22);
}