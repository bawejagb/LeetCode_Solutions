class Solution {
    int dp[500005];
    static bool cmp(const vector<int>&a, const vector<int>&b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int findProfit(vector<vector<int>>&job, int idx, int n){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int temp = idx;
        while(temp<n and job[temp][0]<job[idx][1]) temp++;
        int res;
        res = findProfit(job,temp,n)+job[idx][2];
        if(temp-idx>1) 
            res=max(res,findProfit(job,idx+1,n));
        return dp[idx] = res;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp, -1, sizeof dp);
        int n = profit.size();
        vector<vector<int>> job(n,vector<int>(3));
        for(int i=0;i<n;i++){
            job[i][0] = startTime[i];
            job[i][1] = endTime[i];
            job[i][2] = profit[i];
        }
        sort(job.begin(),job.end(), cmp);
        return findProfit(job, 0,n);
    }
};