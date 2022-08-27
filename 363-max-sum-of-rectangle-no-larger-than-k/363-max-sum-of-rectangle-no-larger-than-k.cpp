class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        //Prefix sum of each row
        for(int i = 0; i< rowSize; i++)
            for(int j = 1; j < colSize; j++)
                matrix[i][j] += matrix[i][j-1];
        
        int maxVal = INT_MIN;
        //Try every possible width of subarray
        for(int i = 0; i< colSize; i++){
            for(int j = i; j < colSize; j++){
                set<int> hmap={0};
                int sum = 0;
                for(int t = 0; t < rowSize; t++){
                    sum += matrix[t][j];
                    if(i>0)
                        sum -= matrix[t][i-1];
                    auto itr = hmap.lower_bound(sum-k);
                    if(itr!=hmap.end())
                        maxVal = max(maxVal, sum-(*itr));
                    hmap.insert(sum);
                }
            }
        }
        return maxVal;
    }
};