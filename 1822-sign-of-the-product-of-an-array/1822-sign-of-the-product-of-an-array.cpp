class Solution {
public:
    int arraySign(vector<int>& nums) {
        short neg = 0;
        for(int num : nums){
            if(num==0) return 0;
            if(num<0){
                neg++;
            }
        }
        return neg%2?-1:1;
    }
};