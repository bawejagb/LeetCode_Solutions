class Solution {
public:
    int partitionString(string s) {
        int res=0;
        int freq[26]{};
        for(char c: s){
            if(freq[c-'a']){
                res++;
                memset(freq,0, sizeof freq);
            }
            freq[c-'a']++;
        }
        res++;
        return res;
    }
};