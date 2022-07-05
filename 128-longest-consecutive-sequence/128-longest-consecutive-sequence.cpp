class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hset;
        for(int n : nums)
            hset.insert(n);
        int res=0;
        for(int n: hset){
            if(hset.find(n-1)==hset.end()){
                int cNum = n;
                int streak = 1;
                while(hset.find(cNum+1)!=hset.end()){
                    cNum++;
                    streak++;
                }
                res = max(res,streak);
            }
        }
        return res;
    }
};