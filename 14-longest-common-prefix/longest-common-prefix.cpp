class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string ans;
        string first=strs[0];
        string last=strs[n-1];
        int m=min(last.size(),first.size());
            for(int j=0;j<m;j++){
                if(strs[0][j]==strs[n-1][j]){
                    ans+=strs[0][j];
                }else{
                    break;
                }
        }
        return ans;
    }
};