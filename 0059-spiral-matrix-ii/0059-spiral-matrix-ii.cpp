class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num=1,left=0,right=n-1,top=0,bottom=n-1;
        vector<vector<int>>matrix(n,vector<int>(n));

        while(left<=right && top<=bottom){
            for(int i=left; i<=right; i++){
                matrix[top][i]=num++;
            }
            top++;

            for(int i=top;i<=bottom;i++){
                matrix[i][right]=num++;
            }
            right--;

            for(int i=right;i>=left;i--){
                matrix[bottom][i]=num++;
            }
            bottom--;

            for(int i=bottom;i>=top;i--){
                matrix[i][left]=num++;
            }
            left++;
        }

        return matrix;
    }
};