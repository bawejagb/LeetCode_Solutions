class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool check[10001]{};
        int i, j, sum, res, n = nums.size();
        i = sum = res = 0;
        for(j=0;j<n;j++){
            sum += nums[j];
            if(check[nums[j]]){
                while(i < j && nums[i]!=nums[j]){
                    sum -= nums[i];
                    check[nums[i]] = false;
                    i++;
                }
                sum -= nums[i];
                check[nums[i]] = false;
                i++;
            }
            check[nums[j]] = true;
            res = max(res,sum);
        }
        return res;
    }
};