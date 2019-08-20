#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	vector<int> res;
	vector<int> Traversal(TreeNode* root) {
		
		postorderTraversal_iter(root);
		return res;
			
	}

	void preorderTraversal(TreeNode *root) {
		if (root == nullptr)
			return;
		res.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}

	/*����ǰ��������ȱ���������ջ���ٱ�����������ѭ���˳������ǵ�ջ���ҵ�ǰ�ڵ�Ϊ�գ�
	���������ǰ�ڵ�Ϊ�գ���˵���Ѿ�����Ҷ�ӽڵ㣬��һ���ͼ�����ջ��������������
	*/
	void preorderTraversal_iter(TreeNode *root) {    
		stack<TreeNode>s;
		while (root != nullptr || !s.empty())
		{
			if (root == nullptr) {
				root = &s.top();
				s.pop();
				root = root->right;
			}else{
				res.push_back(root->val);
				s.push(*root);
				root = root->left;
			}

		}

	}

	//��������������ı�visit()λ�ü���

	void inorderTraversal_iter(TreeNode* root) {
		stack<TreeNode>s;
		while (root != nullptr || !s.empty())
		{
			if (root == nullptr) {
				root = &s.top();
				res.push_back(root->val);
				s.pop();
				root = root->right;
			}
			else {
				s.push(*root);
				root = root->left;
			}

		}
	}

	/*���������������ǰ���������˼·��ÿ����������ջ������Ҷ�ӽڵ���ջ����ʱ������Ҫ�ж��Ƿ�����������
	���û�У�����ʽڵ㣬Ȼ�������ջ������У���Ҫ�ж���һ�η��ʵĽڵ��ǲ���root���ҽڵ㣬�����
	�ͷ��ʼ�����ջ��������ǣ��Ͱ�����������root������ջ*/
	


	void postorderTraversal_iter(TreeNode* root) {
		stack<TreeNode*>s;
		TreeNode *pre = nullptr;
		while (root != nullptr || !s.empty())
		{
			if (root == nullptr) {
				root = s.top();
				if (root->right) {
					if (pre == root->right) {
						res.push_back(root->val);
						pre = root;
						s.pop();
						root = nullptr;    //Ϊ���´μ�����ջ
					}
					else {
						root = root->right;   //��������û���ʣ����ȷ���������
					}
				}
				else {
					res.push_back(root->val);   //û���������������Ȼ�������ջ
					pre = root;
					s.pop();
					root = root->right;
				}
			}else {
				s.push(root);
				root = root->left;
			}
		}

	}

	//��α�����target��d�ֱ�������¼�ò��Ŀ�������Ѿ�����������ȷ��ÿ��������һ�㡣

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>res;
		vector<int>temp;
		queue<TreeNode*>q;
		int target = 1;
		int d = 0;
		if (!root)
			return res;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *pt = q.front();
			temp.push_back(pt->val);
			q.pop();

			if (pt->left)
				q.push(pt->left);
			if (pt->right)
				q.push(pt->right);

			if (target == ++d) {
				target = q.size();
				d = 0;
				res.push_back(temp);
				temp.clear();
			}
		}
		return res;
	}

};







int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	TreeNode *root = &a;

	Solution s;
	auto vec = s.levelOrder(root);
	/*for (auto val : vec) {
		cout << val << endl;
	}*/


	return 0;

}