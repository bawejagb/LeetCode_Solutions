class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum,val,res;
        sum=val=res=0;
        unordered_map<int,int> hmap;
        for(int i=0;i<n;i++){
            sum += nums[i];
            hmap[sum] = i;
        }
        hmap[0] = 0;
        sum -= x;
        for(int i=0;i<n;i++){
            val += nums[i];
            if(hmap.find(val-sum)!=hmap.end()){
                if(val==sum)
                    res = max(res,i-hmap[val-sum]+1);
                else
                    res = max(res, i-hmap[val-sum]);
            }
        }
        return res==0?(sum==0?n:-1):n-res;
    }
};