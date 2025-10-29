class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
         if (n != goal.size()) return false;
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};