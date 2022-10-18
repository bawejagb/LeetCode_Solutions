class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mx=0, i=0, j=0, cnt=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
                while(cnt>k){
                    if(nums[j]==0) cnt--;
                    j++;
                }
            }
            mx = max(mx, i-j+1);
        }
        return mx;
    }
};