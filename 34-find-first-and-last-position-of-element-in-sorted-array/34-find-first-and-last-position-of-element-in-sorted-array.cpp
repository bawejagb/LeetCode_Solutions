class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int r1,r2,left,right,mid;
        r1=r2=-1;
        left=0;
        right=nums.size()-1;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target){
                if(mid==0||nums[mid-1]<target){
                    r1 = mid;
                    break;
                }
                else
                    right = mid-1;
            }
            else if(nums[mid]<target)
                left = mid+1;
            else right = mid-1;
        }
        if(r1!=-1){
            left = 0;
            right = nums.size()-1;
            while(left<=right){
                mid = (left+right)/2;
                if(nums[mid]==target){
                    if(mid==nums.size()-1||nums[mid+1]>target){
                        r2 = mid;
                        break;
                    }
                    else
                        left = mid+1;
                }
                else if(nums[mid]<target)
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return {r1,r2};
    }
};