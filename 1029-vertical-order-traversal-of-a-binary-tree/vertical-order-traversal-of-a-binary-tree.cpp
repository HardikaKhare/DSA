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
    void traverse(map<int, map<int, multiset<int>>>& mp,TreeNode* node,int row,int col){
        if(node==NULL)return;
        mp[col][row].insert(node->val);
        traverse(mp,node->left,row+1,col-1);
        traverse(mp,node->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        vector<vector<int>> ans;
        traverse(mp,root,0,0);
        for (auto &colP : mp) {
            vector<int> temp;
            for (auto &rowP : colP.second) {
                for(auto&vals : rowP.second){
                    temp.push_back(vals);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};