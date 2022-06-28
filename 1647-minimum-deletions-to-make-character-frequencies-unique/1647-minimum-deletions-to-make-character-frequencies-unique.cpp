class Solution {
public:
    int minDeletions(string s) {
        int let[26]{};
        for(char c: s) let[c-'a']++;
        sort(let,let+26);
        unordered_set<int> hset;
        int j,cnt=0;
        for(int i=0;i<26;i++){
            if(let[i]==0) continue;
            if(hset.find(let[i])==hset.end())
                hset.insert(let[i]);
            else{
                j=let[i]-1;
                while(j>0 && hset.find(j)!=hset.end()) j--;
                if(j>0) hset.insert(j);
                cnt += let[i]-j;
            }
        }
        return cnt;
    }
};