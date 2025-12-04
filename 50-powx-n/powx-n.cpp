class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long a=n;
        if(n<0)a=-1*a;
        while(a>0){
            if(a%2==1){
                ans=ans*x;
                a=a-1;
            }else{
                x=x*x;
                a=a/2;
            }
        }
        if(n<0) ans=1/ans;
        return ans;
    }
};