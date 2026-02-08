class Solution {
public:
    int recurse(string& s, long long ans,int idx,int& sign){
        if(idx==s.size()|| !isdigit(s[idx])){
            return ans*sign;
        }
        ans=ans*10+(s[idx]-'0');
        if(ans*sign<INT_MIN) return INT_MIN;
        if(ans*sign>INT_MAX) return INT_MAX;
        return recurse(s,ans,idx+1,sign);
    }
    int myAtoi(string s) {
        int idx=0;
        while(idx<s.size() && s[idx]==' '){
             idx++;
        }
        int sign=1;
        if(s[idx]=='-' || s[idx]=='+'){
            if(s[idx]=='-')sign=-1;
            idx++;
        }
        return recurse(s,0,idx,sign);
    }
};