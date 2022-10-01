class Solution {
public:
    #define LL long long
    int shortestSubarray(vector<int>& nums, int k) { 
       int size = nums.size();
        //presum
        vector<LL> s(size+1);
        for (int i = 1; i <= size; i++)
            s[i] = s[i - 1] + nums[i - 1];
        //increase stack for index
        vector<int> stk(size+1);
        int top = 0;
        int res = INT_MAX;
        for (int i = 1,j=0;i <= size;i++){
            while (j<=top && s[stk[top]] >= s[i])
                top--;
            stk[++top] = i;
            while (j < top && s[stk[j]] <= s[i] - k){
                res = min(res, i - stk[j]);
                j++;
            }
        }
        if (res == INT_MAX) return -1;
        return res;
    }
    
};