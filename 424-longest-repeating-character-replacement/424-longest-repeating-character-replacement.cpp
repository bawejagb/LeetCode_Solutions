class Solution {
public:
    int characterReplacement(string s, int k) {
        int left,windowSize,maxChar,ans;
        left=windowSize=maxChar=ans=0;
        int charCount[26]{};
        for(int i=0;i<s.size();i++){
            windowSize=i-left+1;
            maxChar = max(maxChar,++charCount[s[i]-'A'] );
            if(windowSize-maxChar>k){
                charCount[s[left]-'A']--;
                left++;
            }
            else
                ans=max(ans,windowSize);
        }
        return ans;
    }
};