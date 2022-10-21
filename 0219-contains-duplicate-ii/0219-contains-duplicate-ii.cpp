class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        uint8_t  size = nums.size() - 1;
        for(uint8_t  i = 0; i < size; ++i)
        {
            for(uint8_t  j = i + 1; j <= size; ++j)
                if((nums[i] == nums[j]) &&  j-i <= k)
                    return true;
        }
        
        return false;
    }
};