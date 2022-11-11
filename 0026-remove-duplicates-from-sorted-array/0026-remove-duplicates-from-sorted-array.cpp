class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int a,b;
        a = 0;
        b = 1;
        while(b < nums.size()){
            while(b < nums.size() && nums[a] == nums[b]) b++;
            if(b < nums.size() && nums[a] != nums[b]){
                nums[++a] = nums[b];
            }
        }
        return a+1;
    }
};