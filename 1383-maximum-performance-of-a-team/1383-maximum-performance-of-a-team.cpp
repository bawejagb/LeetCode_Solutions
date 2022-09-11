class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9+7;
        vector<pair<int,int>> engr;
        for(int i=0;i<n;i++)
            engr.push_back({efficiency[i],speed[i]});
        sort(engr.begin(),engr.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        long sum = 0, ans = 0;
        for(int i=n-1;i>=0;i--){
            if(pq.size()==k && engr[i].second>pq.top()){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size()<k){
                sum += engr[i].second;
                pq.push(engr[i].second);
            }
            ans = max(ans, sum*engr[i].first);
        }
        return ans % MOD;
    }
};