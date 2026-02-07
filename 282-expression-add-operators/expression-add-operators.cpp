class Solution {
public:
   void recurse(int idx,long long total,long long last,vector<string>& ans,string s,string& num,int target) {
        if(idx == num.size()){
            if(total == target) ans.push_back(s);
            return;
        }
        long long curr = 0;
        for(int i = idx; i < num.size(); i++){
            if(i > idx && num[idx] == '0') break;
            curr = curr * 10 + (num[i] - '0');
            string part = num.substr(idx, i - idx + 1);
            if(idx == 0){
                recurse(i+1, curr, curr, ans, part, num, target);
            }
            else{
                recurse(i+1, total + curr, curr,ans, s + "+" + part, num, target);
                recurse(i+1, total - curr, -curr,ans, s + "-" + part, num, target);
                recurse(i+1,total - last + last*curr,last*curr,ans, s + "*" + part, num, target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string s = "";
        recurse(0, 0, 0, ans, s, num, target);
        return ans;
    }
};