class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hset;
        int p=0,n=nums.size();
        p=nums[0]%k;
        hset[p]=0;
        hset[0]=-1;
        for(int i=1;i<n;i++){
            p=(p+nums[i])%k;
            if(hset.find(p)!=hset.end()){ 
                if(i-hset[p]>1)
                return true;
            }
            else hset[p]=i;
        }
        return false;
    }
};