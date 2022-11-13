class Solution {
public:
    string reverseWords(string s) {
        int cnt = 0;
        while(s[cnt]==' ') cnt++;
        s.erase(0,cnt);
        cnt = s.size()-1;
        while(s[cnt]==' ') cnt--;
        cnt++;
        s.erase(cnt,s.size()-cnt);
        cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]==' '){
                cnt = i+1;
                while(s[cnt] == ' ') cnt++;
                if(cnt > i+1){
                    s.erase(i+1,cnt-i-1);
                }
            }
        }
        reverse(s.begin(),s.end());
        int idx = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+idx, s.begin()+i);
                idx = i+1;
            }
            else if(i==s.size()-1){
                reverse(s.begin()+idx,s.end());
            }
        }
        return s;
    }
};