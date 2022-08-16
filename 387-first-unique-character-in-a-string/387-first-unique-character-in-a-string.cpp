class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]{};
        int n = s.length();
        for(char c : s) {
            freq[c - 'a']++;
        }
        for(int i = 0; i < n; i++) {
            if(freq[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};