class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> hmap;
        for(int x: nums){
            hmap[x]++;
        }
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(2*nums[i]==k){
                if(hmap[nums[i]]>1){
                    hmap[nums[i]] -= 2;
                    cnt++;
                }
            }
            else if(k>nums[i]&&hmap[nums[i]]>0&&hmap[k-nums[i]]>0){
                hmap[nums[i]]--;
                hmap[k-nums[i]]--;
                cnt++;
            }
        }
        return cnt;
    }
};