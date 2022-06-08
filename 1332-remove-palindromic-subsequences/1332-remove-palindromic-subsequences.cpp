class Solution {
public:
    bool isPalin(string s){
        int n = s.length();
        for(int i = 0, j = n - 1;i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        
        return true;
    }
    int removePalindromeSub(string s) {
        
        if(s.empty()) return 0;
       
        if(isPalin(s)) return 1;
        
        else return 2;
        
    }
};