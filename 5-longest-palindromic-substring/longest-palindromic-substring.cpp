class Solution {
public:
    int exp(const string&s,int i,int j){
        int n=s.size();
         while(i>=0 && j<n&&s[i]==s[j]){
            i--;j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string ans;
        int maxLen=1,start=0;
        for(int mid=0;mid<n;mid++){
        int odd=exp(s,mid,mid);
        int even=exp(s,mid,mid+1);
        int len=max(odd,even);
        if (len > maxLen) {
                maxLen = len;
                start = mid - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};