class Solution {
public:
    void letter(string digits,vector<string>& ans,int idx,string& curr,vector<string>& mpp){
        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<mpp[digits[idx] - '0'].size();i++){
            curr=curr+mpp[digits[idx]-'0'][i];
            letter(digits,ans,idx+1,curr,mpp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mpp={ "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string curr = "";
        letter(digits,ans,0,curr,mpp);
        return ans;
    }
};