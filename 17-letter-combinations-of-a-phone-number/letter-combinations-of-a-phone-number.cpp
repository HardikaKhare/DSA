class Solution {
public:
    void letter(string digits,vector<string>& ans,int idx,string curr,vector<string>& mpp){
        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }
        string dig=mpp[digits[idx] - '0'];
        for(int i=0;i<dig.size();i++){
            letter(digits,ans,idx+1,curr+dig[i],mpp);
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