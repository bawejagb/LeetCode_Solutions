class Solution {
    int palindrome(string s, int start, int end){
        while(start>=0 && end<s.size() && s[start] == s[end]){
            start--;end++;
        }
        return end-start-1;
    }
public:
    string longestPalindrome(string s) {
        int a,b;
        a = b = 0;
        for(int i = 0; i < s.size(); i++){
            int sz1 = palindrome(s,i,i);
            int sz2 = palindrome(s,i,i+1);
            int len = max(sz1,sz2);
            if(len > b-a){
                a = i-(len-1)/2;
                b = i + len/2;
            }
        }
        return s.substr(a,b-a+1);
    }
};