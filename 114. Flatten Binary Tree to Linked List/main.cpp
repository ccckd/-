#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        if(root->left == nullptr && root->right == nullptr)
           return;

        if(root->left && root->right){
           flatten(root->left);
           flatten(root->right);
           TreeNode *left_end = root->left;
           while (left_end->right)
               left_end = left_end->right;
           left_end->right = root->right;
           root->right = root->left;
           root->left = nullptr;
           return;
        }
        if(root->left){
           flatten(root->left);
           root->right = root->left;
           root->left = nullptr;
           return;
        }
        flatten(root->right);
    }
};

int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    a->left = b;
    a->right = c;
    c->right = d;
    Solution s;
    s.flatten(a);
    cout << "ok" << endl;
}