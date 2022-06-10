class Solution {
    int max (int x, int y){
    return x > y ? x : y;
}
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start,end,res = 0;
        start=end=0;
        unordered_set<char> hset;
        while(start < n && end < n){
            if(hset.find(s[start])==hset.end()){
                hset.insert(s[start]);
                start++;
                res = max(res, start-end);
            }
            else{
                hset.erase(s[end]);
                end++;
            }
        }
        return res;
    }
};