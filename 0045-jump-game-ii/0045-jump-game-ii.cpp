class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currJ, maxJ, i, count;
        count = currJ = maxJ = 0;
       for(int i = 0; i < n-1; i++){
            maxJ = max(maxJ, i+nums[i]);
            if(currJ == i){
                currJ = maxJ;
                count++;
                if(currJ >= n-1)
                    break;
            }
        }
        return count;
    }
};