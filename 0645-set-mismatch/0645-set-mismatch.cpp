class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int miss = 1, dub = -1;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                dub = nums[i];
            }
            if(nums[i]==miss) miss++;
        }
        return {dub,miss};
    }
};