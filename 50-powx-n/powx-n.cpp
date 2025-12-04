class Solution {
public:
    double multi(double x, int n,double ans){
        if(n==0) return ans;
        ans=ans*x;
        n--;
        return multi(x,n,ans);
    }
    double myPow(double x, int n) {
        if(x==1.00000)return 1;
        if(n%2==1 && x==-1) return -1; 
        if(n<=INT_MIN) n=INT_MIN/2;
        if(n>=INT_MAX) n=(INT_MAX/2)-1;
        if(n<0){
            x=1/x;
            n=n*(-1);
        }
        return multi(x,n,1.00000);
    }
};