class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int idx,cur,res=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                idx = st.top();
                st.pop();
                cur = heights[idx]*(st.empty()?i:i-1-st.top());
                res = max(res,cur);
            }
            st.push(i);
        }
        while(!st.empty()){
                idx = st.top();
                st.pop();
                cur = heights[idx]*(st.empty()?n:n-1-st.top());
                res = max(res,cur);
            }
        return res;
    }
};