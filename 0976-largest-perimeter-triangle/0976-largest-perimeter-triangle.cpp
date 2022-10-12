class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a,b,c,res=0;
        a=nums[0];
        b=nums[1];
        c=nums[2];
        if(a+b>c) res = max(res,a+b+c);
        for(int i=3;i<nums.size();i++){
            a=b;
            b=c;
            c=nums[i];
            if(a+b>c) res = max(res,a+b+c);
        }
        return res;
    }
};