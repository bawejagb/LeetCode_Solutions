class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> vs,vt;
        for(char c : s){
            if(c=='#'&&!vs.empty()) vs.pop_back();
            else if(c!='#') vs.push_back(c);
        }
        for(char c : t){
            if(c=='#'&&!vt.empty()) vt.pop_back();
            else if(c!='#') vt.push_back(c);
        }
        if(vs.size()==vt.size()){
            for(int i=0;i<vs.size();i++){
                if(vs[i]!=vt[i]) return false;
            }
            return true;
        }
        return false;
    }
};