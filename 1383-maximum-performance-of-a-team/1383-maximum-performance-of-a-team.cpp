class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9+7;
        pair<int,int> engr[n];
        for(int i=0;i<n;i++)
            engr[i] = {efficiency[i],speed[i]};
        sort(engr,engr+n);
        priority_queue<int,vector<int>,greater<int>> pq;
        long sum = 0, ans = 0;
        for(int i=n-1;i>=0;i--){
            sum += engr[i].second;
            pq.push(engr[i].second);
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum*engr[i].first);
        }
        return ans % MOD;
    }
};