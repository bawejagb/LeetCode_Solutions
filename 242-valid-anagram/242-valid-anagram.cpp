class Solution {
public:
    bool isAnagram(string s, string t) {
        int hmap[26]{};
        for(char c : s){
            hmap[c-'a']++;
        }
        for(char c : t){
            hmap[c-'a']--;
        }
        for(int i=0;i<26;i++)
            if(hmap[i]!=0) return false;
        return true;
    }
};