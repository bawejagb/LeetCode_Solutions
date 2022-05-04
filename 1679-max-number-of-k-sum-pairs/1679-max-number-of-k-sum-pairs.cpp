class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt=0;
        int a,b;
        a=0;
        b=n-1;
        while(a<b){
            if(nums[a]+nums[b]==k){
                cnt++;
                a++;
                b--;
            }
            else if(nums[a]+nums[b]>k)
                b--;
            else
                a++;
        }
        return cnt;
    }
};