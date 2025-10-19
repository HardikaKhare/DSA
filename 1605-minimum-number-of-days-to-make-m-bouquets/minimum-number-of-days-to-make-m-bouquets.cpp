class Solution {
public:
    bool bloom(vector<int>b,int m,int k,int day){
        int no=0;
        int count=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<=day){
                count++;
            }
            else{
                no+=count/k;
                count=0;
            }
        }
        no+=count/k;
        if(no>=m)return true;
        else return false;
    }
    int minDays(vector<int>& b, int m, int k) {
        int n=b.size();
        int low= *min_element(b.begin(),b.end());;
        int high= *max_element(b.begin(),b.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int a=bloom(b,m,k,mid);
            if(a==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};