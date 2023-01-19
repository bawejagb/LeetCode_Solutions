class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int hmap[10001]{};
        hmap[0]=1;
        int  res=0,sum=0,temp;
        for(int num : nums){
            sum += num;
            temp = (sum%k+k)%k;
            res += hmap[temp];
            hmap[temp]++;
        }
        return res;
    }
};