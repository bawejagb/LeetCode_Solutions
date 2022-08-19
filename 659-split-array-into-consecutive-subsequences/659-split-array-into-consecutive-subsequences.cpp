class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int hmap[2002]{},pmap[2002]{};
        for(int i=0;i<nums.size();i++){ nums[i]+=1000;hmap[nums[i]]++;}
        for(int x : nums){
            if(hmap[x]==0) continue;
            if(pmap[x]>0){
                hmap[x]--;
                pmap[x]--;
                pmap[x+1]++;
            }
            else{
                if(hmap[x+1]==0 || hmap[x+2] == 0) return false;
                hmap[x]--;
                hmap[x+1]--;
                hmap[x+2]--;
                pmap[x+3]++;
            }
        }
        return true;
    }
};