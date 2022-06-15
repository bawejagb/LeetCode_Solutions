class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),sortByLength);
        int ans = 0;
        for(string word : words){
            
            for(int i = 0; i<word.length();i++){
                string pred = word.substr(0,i)+word.substr(i+1);
                dp[word] = max(dp[word],dp[pred]+1);
            }
        ans = max(dp[word],ans);
       
    }
         return ans;
    }
    
    static bool sortByLength(string &s1, string &s2){
        return s1.length()<s2.length();
    }
};