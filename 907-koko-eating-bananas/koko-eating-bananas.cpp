class Solution {
public:
    long long rate(vector<int>&piles,int speed){
        long long time=0;
        for(int j=0;j<piles.size();j++){
                time += (piles[j] + speed-1) / speed;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(n==h)return *max_element(piles.begin(), piles.end());

        int high=*max_element(piles.begin(), piles.end());
        int low=1;
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            long long time=rate(piles,mid);
            if(time<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};