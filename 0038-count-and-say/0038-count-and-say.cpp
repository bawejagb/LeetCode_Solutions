class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int cnt=1;
        for(int i = 2; i<= n; i++){
            string p = "";
            s = s+"&";
            for(int i = 1; i<s.size();i++){
                if(s[i]!=s[i-1]){
                    p = p+to_string(cnt);
                    p = p+s[i-1];
                    cnt=1;
                }
                else cnt++;
            }
            s = p;
        }
        return s;
    }
};