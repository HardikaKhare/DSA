class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    if(st.top()=='(' && s[i]!=')' || 
                    st.top()=='{' && s[i]!='}'||
                    st.top()=='[' && s[i]!=']'){
                        return false;
                    }
                    else{
                    st.pop();
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.size()==0)return true;
        return false;
    }
};