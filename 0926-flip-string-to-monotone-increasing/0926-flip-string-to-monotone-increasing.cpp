class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res=0,temp=0;
        for(char c : s){
            if(c=='1')
                temp++;
            else
                res = min(res+1, temp);
        }
        return res;
    }
};