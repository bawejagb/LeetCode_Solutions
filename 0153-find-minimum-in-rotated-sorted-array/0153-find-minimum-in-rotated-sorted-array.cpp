class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid=0, left=0, right = nums.size()-1;
        if(nums[left]<nums[right]) return nums[left];
        while(left<right){
            mid = (left+right)/2;
            if(mid<nums.size()-1 and nums[mid]>nums[mid+1]){
                mid++;
                break;
            }
            if(mid>0 and nums[mid-1]>nums[mid])
                break;
            if(nums[left]<nums[mid])
                left = mid+1;
            else
                right = mid-1;
        }
        return nums[mid];
    }
};