class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a,b, res = 0;
        a = 0;
        b = nums.size()-1;
        while(a < b){
            res += (nums[b]-nums[a]);
            a++;b--;
        }      
        return res;
    }
};