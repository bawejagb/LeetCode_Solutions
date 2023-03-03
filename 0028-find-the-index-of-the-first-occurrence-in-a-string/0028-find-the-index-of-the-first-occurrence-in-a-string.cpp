class Solution {
public:
    int strStr(string haystack, string needle) {
        int res=-1;
        int nSize = needle.size();
        for(int i=0;i<haystack.size();i++){
            if(needle[0] != haystack[i]) continue;
            if(needle == haystack.substr(i,nSize)){
                res = i;
                break;
            }
        }
        return res;
    }
};