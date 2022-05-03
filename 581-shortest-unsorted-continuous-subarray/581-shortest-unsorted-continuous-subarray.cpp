class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> snums = nums;
        sort(snums.begin(),snums.end());
        int a,b, n = nums.size();
        a=0;
        b = n-1;
        for(int i=0;i<n;i++){
            if(nums[i]==snums[a]) a++;
            else break;
        }
        for(int i = n-1;i>=0;i--){
            if(nums[i]==snums[b]) b--;
            else break;
        }
        if(a<=b) return b-a+1;
        return 0;
    }
};