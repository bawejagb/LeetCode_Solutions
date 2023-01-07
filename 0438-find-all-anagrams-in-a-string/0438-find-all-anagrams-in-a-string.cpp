class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, hmap1(26,0), hmap2(26,0);
        for(char c : p)
            hmap1[c-'a']++;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(hmap1[s[i]-'a']==0 ){
                start = i+1;
                hmap2.assign(hmap2.size(), 0);
                continue;
            }
            else if(hmap2[s[i]-'a'] >= hmap1[s[i]-'a']){
                while(hmap2[s[i]-'a'] >= hmap1[s[i]-'a']){
                    hmap2[s[start]-'a']--;
                    start++;
                    continue;
                }
            }
            hmap2[s[i]-'a']++;
            if(hmap1==hmap2){
                res.push_back(start);
                hmap2[s[start]-'a']--;
                start++;
            }
        }
        return res;
    }
};