class Solution {
    pair<int,int> dp[41][41];
    pair<int,int> backtrack(int start, int end, vector<int>& arr){
        if(start==end) return dp[start][end] = {arr[start],0};
        if(dp[start][end].first != -1) return dp[start][end];
        int nonleafsum = INT_MAX;
        int maxleaf = 0;
        for(int i = start; i < end; i++){
            auto left = backtrack(start,i,arr);
            auto right = backtrack(i+1,end,arr);
            nonleafsum = min(nonleafsum,left.first*right.first+left.second+right.second);
            maxleaf = max({maxleaf,left.first,right.first});
        }
        return dp[start][end] = {maxleaf,nonleafsum};
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        for(int i=0;i<41;i++) for(int j=0;j<41;j++) dp[i][j]={-1,-1};
        return backtrack(0,arr.size()-1,arr).second;
    }
};