class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        int notAidx = -1;
        int notAcnt = 0;
        for(int i=0;i<n;i++){
            if(palindrome[i]!='a'){
                notAidx = notAidx == -1 ? i : notAidx;
                notAcnt++;
            }
        }
        if(notAidx>=0 && notAcnt>1) palindrome[notAidx]='a';
        else palindrome[n-1] = 'b';
        return palindrome;
    }
};