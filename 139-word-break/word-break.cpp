class Solution {
public:
    bool check(string &s, int start,unordered_set<string>& dict,vector<int>& memo) {

        if(start == s.size()) return true;
        if(memo[start] != -1)
            return memo[start];

        for(int end = start; end < s.size(); end++) {
            string prefix = s.substr(start, end-start+1);

            if(dict.count(prefix)) {
                if(check(s, end+1, dict, memo))
                    return memo[start] = 1; 
            }
        }

        return memo[start] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int start=0;
        vector<int> memo(s.size(), -1);
        return check(s,start,dict,memo);
    }
};