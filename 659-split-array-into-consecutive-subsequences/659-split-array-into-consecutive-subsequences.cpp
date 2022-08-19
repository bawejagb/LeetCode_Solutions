class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> hmap,pmap;
        for(int x: nums) hmap[x]++;
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