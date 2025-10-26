class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                
                int curr = mat[i][j];
                bool top = (i == 0 || mat[i-1][j] < curr);
                bool bottom = (i == n-1 || mat[i+1][j] < curr);
                bool left = (j == 0 || mat[i][j-1] < curr);
                bool right = (j == m-1 || mat[i][j+1] < curr);

                if (top && bottom && left && right)
                    return {i, j};
           }
        }
        return {-1,-1};
    }
};