class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res=1;
        int n = nums.size();
        vector<int> seq(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(nums[j]<nums[i]&&seq[j]>=seq[i])
                    seq[i]=seq[j]+1;
            }
        }
        for(int i=1;i<n;i++)
            res = max(res,seq[i]);
        return res;
    }
};