#include<stack>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode> left, right;
        while (1)
        {
            if(p && q && p->val == q->val){
                left.push(*p);
                right.push(*q);
                p = p->left;
                q = q->left;
            }else if (p == nullptr && q == nullptr)
            {
                if(left.empty() && right.empty())
                    return true;
                p = &left.top();
                p = p->right;
                q = &right.top();
                q = q->right;
                left.pop();
                right.pop();

            }else{
                return false;
            }
            
        }
        
    }
};

int main(){
    Solution s;
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *x = new TreeNode(1);
    TreeNode *y = new TreeNode(2);
    TreeNode *z = new TreeNode(5);
    a->left = b;
    a->right = c;
    x->left = y;
    x->right = z;

    cout << s.isSameTree(a, x) << endl;
    int res;
    cin >> res;
}