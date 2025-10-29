class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
         if (n != goal.size()) return false;
       for (int i = 0; i < n; i++) {
            // rotate s by one position each time
            reverse(s.begin(), s.begin() + 1);
            reverse(s.begin() + 1, s.end());
            reverse(s.begin(), s.end());
            
            if (s == goal) return true;
       }
        return false;
    }
};