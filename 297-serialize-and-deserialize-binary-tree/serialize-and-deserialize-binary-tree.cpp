/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data ="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(!node)data+="*,";
            else{
                data+=to_string(node->val)+',';
                q.push(node->left);
                q.push(node->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0 || data[0]=='*') return NULL;
        int i = 0;
        string val = "";
        while(data[i] != ','){
            val += data[i];
            i++;
        }
        i++;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            string left = "";
            while(data[i] != ','){
                left += data[i];
                i++;
            }
            i++;
            if(left != "*"){
                TreeNode* l = new TreeNode(stoi(left));
                node->left = l;
                q.push(l);
            }
            string right = "";
            while(data[i] != ','){
                right += data[i];
                i++;
            }
            i++;
            if(right != "*"){
                TreeNode* r = new TreeNode(stoi(right));
                node->right = r;
                q.push(r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));