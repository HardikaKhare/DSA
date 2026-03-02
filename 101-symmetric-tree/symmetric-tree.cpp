/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool sym(TreeNode* a,TreeNode* b){
        if(!a || !b)return a==b;
        return (a->val==b->val) && sym(a->left,b->right) && sym(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return sym(root->left,root->right);
    }
};