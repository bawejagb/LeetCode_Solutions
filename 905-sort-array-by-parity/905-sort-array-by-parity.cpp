class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int a,b,n=nums.size();
        a=b=0;
        while(b<n&&nums[b]%2==0) b++;
        a = b;
        while(b<n){
            if(nums[b]%2==1)b++;
            else{
                swap(nums[a],nums[b]);
                a++;b++;
            }
        }
        return nums;
    }
};