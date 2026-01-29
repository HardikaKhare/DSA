class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int i=0,n=s.length(),sign=1;
        while(s[i]==' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        while(s[i]=='0')i++;
        while(isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;
            i++;
        }
        return ans*sign;
    }
};