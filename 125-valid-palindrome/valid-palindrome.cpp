class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])) result+=tolower(s[i]);
        }
        int l=0,r=result.length()-1;
        while(l<r){
            if (result[l] != result[r]) return false;
                l++;
                r--;
        }
        return true;
    }
};