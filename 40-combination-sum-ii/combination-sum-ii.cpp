class Solution {
public:
void sums(vector<int>& candidates, int target,int sum,int idx,vector<int>& val,vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(val);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1] ) continue;
        val.push_back(candidates[i]);
        sums(candidates,target,sum+candidates[i],i+1,val,ans);
        val.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<int>val;
        vector<vector<int>>ans;
        int sum=0;
        int idx=0;
        sums(candidates,target,sum,idx,val,ans);
        return ans;
    }
};