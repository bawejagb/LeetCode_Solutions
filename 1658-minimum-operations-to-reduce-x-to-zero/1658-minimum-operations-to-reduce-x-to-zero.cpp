class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
      int sum = 0;
      for(int i = 0;i<n;i++){
        sum += nums[i];
      }
      if(sum < x)return -1;
      if(sum == x)return n;
      int current_sum = 0;
      int target = sum - x;
      int maxi = 0;
      int start = 0;
      for(int i = 0;i<nums.size();i++){
        current_sum += nums[i];
        while(current_sum > target){
          current_sum -= nums[start++];
        }
        if(current_sum == target){
          maxi = max(maxi,i-start+1);
        }
      }return maxi == 0 ? -1 : n-maxi;
    }
};