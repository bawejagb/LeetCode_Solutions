class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> cmin(n);
        cmin[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            cmin[i] = min(cmin[i - 1], nums[i]);
        }
        stack<int> stack;
        for(int i = n - 1; i >= 1; --i) {
            while(stack.size() && stack.top() < nums[i]) {
                if(cmin[i - 1] < stack.top())
                    return true;
                stack.pop();
            }

            stack.push(nums[i]);
        }

        return false;
    }
};