class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start, end, mid;
        start=0;
        end=nums.size()-1;
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                start=mid+1;
            }
            else
                end = mid-1;
        }
        return start;
    }
};