class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<int>hash(n,1);
        if(n > 0) hash[0] = 0;
        if(n > 1) hash[1] = 0;
        for(int i = 2; i*i< n; i++) {
            if(hash[i]==1){
                for(int j=i*i;j<n;j+=i){
                    hash[j]=0;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(hash[i]==1){
                cnt++;
            }
        }
        return cnt;
    }
};