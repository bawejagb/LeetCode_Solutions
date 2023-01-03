class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid=0, left=0, right = nums.size()-1;
        while(left<right){
            mid = (left+right)/2;
            if(nums[right]<nums[mid])
                left = mid+1;
            else
                right = mid;
        }
        return nums[left];
    }
};