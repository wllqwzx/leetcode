#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL){
            return t2;
        }else if(t2 == NULL){
            return t1;
        }else{
            int v = t1->val + t2->val;
            TreeNode *l, *r;
            l = mergeTrees(t1->left, t2->left);
            r = mergeTrees(t1->right, t2->right);
            TreeNode *res = new TreeNode(v);
            res->left = l;
            res->right = r;
            return res;
        }
    }
};



int main(){
    return 0;
}