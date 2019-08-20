#include <iostream>
#include <vector>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void TreeInsert(TreeNode* t, int x){
    if(t == nullptr)
        t = new TreeNode(x);
    else{
        if(x > t->val){
            if(t->right == nullptr)
                t->right = new TreeNode(x);
            else
                TreeInsert(t->right, x);
        }else {
            if (t->left == nullptr)
                t->left = new TreeNode(x);
            else
                TreeInsert(t->left, x);
        }
    }
}

TreeNode* deepCopy(TreeNode *t){
    if(t == nullptr)
        return nullptr;
    TreeNode *cpy = new TreeNode(t->val);
    cpy->left = deepCopy(t->left);
    cpy->right = deepCopy(t->right);

    return  cpy;
}




class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> ary;
        for(int i = 1; i <= n; ++i){
            ary.push_back(i);
        }
        for(int i = 0; i < ary.size(); ++i){
            TreeNode* t = new TreeNode(ary[i]);
            vector<int> ary_temp = ary;
            ary_temp.erase(ary_temp.begin());
            gTrees(ary_temp, t);
        }
        return res;

    }

private:
    void gTrees(vector<int> ary, TreeNode* t){
        if(ary.size() == 0){
            res.push_back(t);
            return;
        }
        for(int i = 0; i < ary.size(); ++i){
            TreeNode* cpy = deepCopy(t);
            TreeInsert(cpy, ary[i]);
            vector<int> ary_temp = ary;
            ary_temp.erase(ary_temp.begin());
            gTrees(ary_temp, cpy);
        }
        delete t;
    }

    vector<TreeNode*> res;

};






int main() {
    Solution s;
    vector<TreeNode*> res = s.generateTrees(3);
    cout << res.size() << endl;
}