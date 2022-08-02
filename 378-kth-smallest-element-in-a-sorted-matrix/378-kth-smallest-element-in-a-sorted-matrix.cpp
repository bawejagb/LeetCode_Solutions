class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int ans=0;
        while(low<=high){
            int mid=low + (high-low)/2;
            int count_smaller=0;
            for(int i=0;i<n;i++){
                count_smaller+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count_smaller<k)
                low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        
        return ans;
        
    }
};