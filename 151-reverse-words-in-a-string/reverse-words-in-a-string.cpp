class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n=s.size();
        int i=0;
        
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            string word;
        while(s[i]!=' ' && i<n){
            word+=s[i];
            i++;
        }
        reverse(word.begin(),word.end());
        if(word.size()>0)
        ans+=' '+word;
        }
        return ans.substr(1);
    }
};