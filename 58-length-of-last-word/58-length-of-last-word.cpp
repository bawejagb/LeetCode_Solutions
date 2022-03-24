class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool fg=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                len++;
                fg=1;
            }
            else if(fg) break;
        }
        return len;
    }
};