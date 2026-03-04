/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* node,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(node==NULL)return;
       if(node->left){
            mpp[node->left] = node;
            parent(node->left, mpp);
        }
        if(node->right){
            mpp[node->right] = node;
            parent(node->right, mpp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        parent(root,mpp);
        vector<int>ans;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*>q;
        q.push(target);
        visited.insert(target);
        int distance=0;
        while(!q.empty()){
            int size = q.size();
            if(distance==k){
                for(int i=0;i<size;i++){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            for(int i = 0; i < size; i++) {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(mpp[node] && !visited.count(mpp[node])){
                    visited.insert(mpp[node]);
                    q.push(mpp[node]);
                }
            }
            distance++;
        }
        return ans;
    }
};