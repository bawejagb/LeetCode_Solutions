class Solution {
    int kadane(char a, char b, string s){
        int cnt =0, res =0;
        bool conts = false;
        for(char c : s){
            if(a==c) cnt++;
            else if(b==c){
                cnt--;
                conts = true;
            }
            if(conts) res = max(res, cnt);
            else res = max(res, cnt-1);
            if(cnt<0){
                conts = false;
                cnt = 0;
            }
        }
        return res;
    }
public:
    int largestVariance(string s) {
        int res=0;
        int cMap[26]{};
        for(char c: s) cMap[c-'a']++;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i != j && cMap[i]>0 && cMap[j]>0)
                    res = max(res, kadane(i+'a',j+'a',s));
            }
        }
        return res;
    }
};