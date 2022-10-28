class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        stack<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top()>nums[i] and k-st.size()<=n-i-1)
                st.pop();
            if(k>st.size())
                st.push(nums[i]);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};