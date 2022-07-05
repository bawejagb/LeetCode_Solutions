class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) { return 0; }
    sort(nums.begin(), nums.end());
    int max_len = 0,len=1,pre=nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (pre == nums[i]) { continue; }
        else if (pre != nums[i]&&nums[i]-pre==1) {
            len++;
            pre = nums[i];
        }
        else {
            if (max_len < len) { max_len = len; }
            pre = nums[i];
            len = 1;
        }
    }
    return max(max_len,len);
    }
};