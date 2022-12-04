class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int minIdx = 0;
        int n = nums.size();
        long nDif,left=0,right=0,dif=1e10;
        for(int i=0;i<n;i++)
            right += nums[i];
        for(int i = 0; i<n-1;i++){
            left += nums[i];
            right -= nums[i];
            nDif = abs((left/(i+1))-(right/(n-i-1)));
            if(nDif<dif){
                dif = nDif;
                minIdx = i;
            }
        }
        left += nums[n-1];
        nDif = (left/n);
        if(nDif<dif){
            dif = nDif;
            minIdx = n-1;
        }
        return minIdx;
    }
};