class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int a=0;
        while(i<n){
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }
            nums[a]=nums[i];
            a++;
            i++;
        }
        return a;
    }
};