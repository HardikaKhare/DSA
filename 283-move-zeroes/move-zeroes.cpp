class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0)count++;
            if(nums[j]!=0){
                nums[i]=nums[j];
                i++;
            }
        }
        int a=n-i;
        while(a>0){
            nums[i]=0;
            a--;
            i++;
        }
    }
};