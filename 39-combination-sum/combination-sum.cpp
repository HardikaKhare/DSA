class Solution {
public:
    void sums(vector<int>& candidates, int target,int sum,int idx,vector<int>& val,vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(val);
            return;
        }
        if(idx==candidates.size() || sum>target){
            return;
        }
        val.push_back(candidates[idx]);
        sums(candidates,target,sum+candidates[idx],idx,val,ans);
        val.pop_back();
        sums(candidates,target,sum,idx+1,val,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>val;
        vector<vector<int>>ans;
        int sum=0;
        int idx=0;
        sums(candidates,target,sum,idx,val,ans);
        return ans;
    }
};