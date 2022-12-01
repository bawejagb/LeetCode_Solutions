class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels({'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int count=0;
        int i=0, j= s.size()/2;
        while(j<s.size()){
            if(vowels.find(s[j++])!=vowels.end()) count--;
            if(vowels.find(s[i++])!=vowels.end()) count++;
        }
        return count==0;
    }
};