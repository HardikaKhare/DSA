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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* node=root;
        while(node!=NULL || !st.empty()){
            if(node !=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        ans.push_back(temp->val);
                        st.pop();
                    }
                }
                else{
                    node=temp;
                }
            }
        }
        return ans;
    }
};