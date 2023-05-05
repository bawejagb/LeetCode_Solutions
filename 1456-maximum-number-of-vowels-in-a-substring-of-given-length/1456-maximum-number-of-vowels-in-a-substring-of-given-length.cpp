class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vowels = {'a','e','i','o','u'};
        int cnt=0,mCnt=0;
        int j=0,i=0;
        for(;i<k;i++){
            if(vowels.find(s[i])!=vowels.end())
                cnt++;
        }
        mCnt = max(mCnt,cnt);
        for(;i<s.size();i++,j++){
            if(vowels.find(s[i])!=vowels.end())
                cnt++;
            if(vowels.find(s[j])!=vowels.end())
                cnt--;
            mCnt = max(mCnt,cnt);
        }
        return mCnt;
    }
};