class Solution {
public:
    void helper(int open,int close,string curr,vector<string>&ans,int n){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            helper(open+1,close,curr+"(",ans,n);
        }
        if(close<open){
            helper(open,close+1,curr+")",ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(0,0,"",ans,n);
        return ans;
    }
};