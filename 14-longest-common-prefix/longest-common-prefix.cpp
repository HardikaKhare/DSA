class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if (n==0) return "";
        sort(strs.begin(),strs.end());
        string ans;
        string first=strs[0];
        string last=strs[n-1];
        int m=min(last.size(),first.size());
            for(int j=0;j<m;j++){
                if(first[j]==last[j]){
                    ans+=first[j];
                }else{
                    break;
                }
        }
        return ans;
    }
};