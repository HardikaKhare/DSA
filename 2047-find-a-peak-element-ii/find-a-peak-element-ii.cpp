class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxi = INT_MIN;
            int row = 0;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];
                    row=i;
                    
                }
            }
                bool left = (mid==0 ||mat[row][mid-1] < maxi);
                bool right = (mid==m-1||mat[row][mid+1] < maxi);

                if (left && right)
                    return {row,mid};
                else if(right){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
        }
        
        return {-1,-1};
    }
};