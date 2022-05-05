class Solution {
public:
    unordered_map<int, bool>dp;
    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }
    
    bool dfs(vector<int>&stones, int pos, int k) {
        int key = pos | k << 11;
        
        if(dp.find(key) != dp.end())
            return dp[key];
        
        for(int i=pos+1; i<stones.size(); i++) {
            int gap = stones[i] - stones[pos];
            if(gap < k-1) continue;
            if(gap > k+1) return dp[key] = false;
            if( dfs(stones, i, gap) ) 
                return dp[key] = true;
        } 
        
        return dp[key] = pos == stones.size()-1;
    }
};