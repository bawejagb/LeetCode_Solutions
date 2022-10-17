class Solution {
public:
    int longestSubstring(string s, int k) {
        int freq[26];
        int maxUnique = 0;
        memset(freq,0,sizeof(freq));
        for(char c : s){
            if(freq[c-'a']==0) maxUnique++;
            freq[c-'a']++;
        }
        int res=0;
        for(int i = 1; i <= maxUnique; i++){
            memset(freq,0,sizeof(freq));
            int left=0,right=0,idx=0,unique=0,countK=0;
            while(right<s.size()){
                if(unique<=i){
                    idx = s[right]-'a';
                    if(freq[idx]==0) unique++;
                    freq[idx]++;
                    if(freq[idx]==k) countK++;
                    right++;
                }
                else{
                    idx = s[left]-'a';
                    if(freq[idx]==k) countK--;
                    freq[idx]--;
                    if(freq[idx]==0) unique--;
                    left++;
                }
                if(unique==i && unique==countK)
                    res = max(res,right-left);
            }       
        }
        return res;
    }
};