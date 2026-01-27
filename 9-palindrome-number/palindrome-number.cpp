class Solution {
public:
    bool isPalindrome(int x) {
        double rev=0;
        int a=x;
        while(x>0){
            int l=x%10;
            rev=(rev*10)+l;
            x=x/10;
        }
        if(a==rev) return true;
        else  return false;
    }
};