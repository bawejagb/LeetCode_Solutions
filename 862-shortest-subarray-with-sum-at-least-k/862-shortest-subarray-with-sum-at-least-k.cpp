class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans=INT_MAX;
        long sum=0;
        deque<pair<long,int>> dq;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum>=k) ans = min(ans, i+1);
            while(!dq.empty() && (sum-dq.front().first)>=k){
                ans = min(ans, i-dq.front().second);
                dq.pop_front();
            }
            while(!dq.empty() && sum < dq.back().first)
                dq.pop_back();
            dq.push_back({sum,i});
        }
        return ans==INT_MAX?-1: ans;
    }
};