class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
         if (n != goal.size()) return false;
        string doubledS = s + s;
        if( doubledS.find(goal) != string::npos) return true;
        else return false;
    }
};