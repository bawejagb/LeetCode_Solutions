class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(),nums.begin()+k);
        auto mid = next(window.begin(),k/2);
        vector<double> result;
        for (int i = k;;  i++) {
            result.push_back((double(*mid) + *next(mid,k%2-1))/2);
            if (i == nums.size())
                return result;
            
            int incr = INT_MAX;
            if (k > 2) {
                if (((nums[i] < *mid) && (nums[i-k] <*mid))  ||
                    ((nums[i] > *mid) && (nums[i-k] > *mid))) {
                    incr = 0;
                } else if (((nums[i-k] < *mid) && (nums[i] > *mid))) {
                    incr = 1;
                } else if (((nums[i-k] > *mid) && (nums[i] < *mid))) {
                    incr = -1;
                }
            }
            if ((nums[i] == *mid) && (nums[i-k] == *mid)) {
                mid = window.insert(nums[i]);
                incr = 0;
            } else
                window.insert(nums[i]);
            window.erase(window.find(nums[i-k]));
            if (incr == INT_MAX) mid = next(window.begin(),k/2);
            else if (incr == 1) mid++;
            else if (incr == -1) mid--;
        }
        return result;
        
    }
};