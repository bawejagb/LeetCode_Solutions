class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int val1,val2;
        val1 = val2 = INT_MAX;
        for(int num : nums){
            if(num <= val1) val1 = num;
            else if(num <= val2) val2 = num;
            else return true;
        }
        return false;
    }
};