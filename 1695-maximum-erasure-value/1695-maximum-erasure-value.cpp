class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> arr(10001,false);
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxx = 0;
        while(j < n){
            sum += nums[j];
            if(arr[nums[j]] == true){
                while(i < j && nums[i]!=nums[j]){
                    sum -= nums[i];
                    arr[nums[i]] = false;
                    i++;
                }
                sum -= nums[i];
                arr[nums[i]] = false;
                i++;
            }
            // cout << sum << endl;
            arr[nums[j]] = true;
            maxx = max(maxx,sum);
            j++;
        }
        return maxx;
    }
};