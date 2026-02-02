class Solution {
public:
    void subset(vector<vector<int>>&ans,int k, int n,vector<int>val,int sum,int idx){
        if(val.size()==k && sum==n){
            ans.push_back(val);
            return;
        }
        if(sum>n ) return;
        for(int i=idx;i<=9;i++){
            val.push_back(i);
            subset(ans,k,n,val,sum+i,i+1);
            val.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>val;
        subset(ans,k,n,val,0,1);
        return ans;
    }
};