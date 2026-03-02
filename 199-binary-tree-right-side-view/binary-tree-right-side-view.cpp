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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp;
        vector<int> ans;
        if(!root) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int row = temp.second;
            if(mp.find(row)==mp.end()){
                 mp[row]=node->val;
            }
            if(node->right)q.push({node->right,row+1});
            if(node->left)q.push({node->left,row+1});
        }
        for(auto&p :mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};