class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt=0;
        bool alpha[26]{};
        for(char c : sentence){
            if(!alpha[c-'a']) alpha[c-'a']=true,cnt++;
            if(cnt==26) return true;
        }
        return false;
    }
};