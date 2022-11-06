class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        int len = s.size();
        string s2 = s+s;
        string res= s;
        for(int i=1;i<len;i++){
            res = min(res, s2.substr(i,len));
        }
        return res;
    }
};