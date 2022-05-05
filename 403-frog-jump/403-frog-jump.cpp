class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,set<int>> hmap;
        int n = stones.size();
        for(int x : stones){
            hmap[x].insert(0);
        }
        int steps;
        if(stones[1]==1)
            hmap[stones[1]].insert(1);
        else return false;
        for(int i = 1; i < n; i++){
            for(auto j=++hmap[stones[i]].begin();j!=hmap[stones[i]].end();j++){
                steps = *j;
                if(steps>1&&hmap[stones[i]+steps-1].size()>0)
                    hmap[stones[i]+steps-1].insert(steps-1);
                if(hmap[stones[i]+steps].size()>0)
                    hmap[stones[i]+steps].insert(steps);
                if(hmap[stones[i]+steps+1].size()>0)
                    hmap[stones[i]+steps+1].insert(steps+1);
                if(hmap[stones[n-1]].size()>1) return true;
            }
        }
        return false;
    }
};