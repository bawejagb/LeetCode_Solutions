class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        if(word.size()==1) return true;
        for(char c : word)
            if(isupper(c)) count++;
        if(count==1 and isupper(word[0])) return true;
        else if(count==0 || count==word.size()) return true;
        else return false;
    }
};