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
    void traverse(TreeNode* root,vector<int>& pre){
        if(!root)return;
        pre.push_back(root->val);
        traverse(root->left,pre);
        traverse(root->right,pre);
    }
    void flatten(TreeNode* root) {
        vector<int>pre;
        TreeNode* node=root;
        traverse(root,pre);
        for(int i=1;i<pre.size();i++){
            TreeNode* next=new TreeNode(pre[i]);
            node->left=NULL;
            node->right=next;
            node = node->right;
        }
    }
};