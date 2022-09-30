class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=0,n=nums.size();
        for(int num : nums){
            l = max(l,num);
            r += num;
        }
        int mid=0,res=0;
        while(l<=r){
            mid = l+(r-l)/2;
            int cnt=0,tempSum=0;
            for(int i=0;i<n;i++){
                tempSum += nums[i];
                if(tempSum>mid){
                    tempSum = nums[i];
                    cnt++;
                }
            }
            cnt++;
            if(cnt<=m){
                r=mid-1;
                res = mid;
            }
            else l = mid+1;
        }
        return res;
    }
};