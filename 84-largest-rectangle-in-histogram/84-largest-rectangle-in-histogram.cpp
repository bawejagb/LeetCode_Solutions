class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>s;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s.empty() || heights[i]>=heights[s.top()]) {
                s.push(i);
            }
            
            else {
                int idx = s.top();
                s.pop();
                
                int curr_ans = heights[idx] * (s.empty()?i:i-1-s.top());
                ans = max(ans,curr_ans);
                i--;
            }
        }
        while(!s.empty()) {
            int idx = s.top();
            s.pop();
            int curr_ans = heights[idx] * (s.empty()?n:n-1-s.top());
            ans = max(ans,curr_ans);
        }
        return ans;
    }
};