class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int a,b;
        a = n;
        b = 0;
        vector<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.back()]>nums[i])
                a = min(a, st.back()),st.pop_back();
            st.push_back(i);
        }
        st.clear();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.back()]<nums[i])
                b = max(b,st.back()),st.pop_back();
            st.push_back(i);
        }
        return a<=b? b-a+1:0;
    }
};