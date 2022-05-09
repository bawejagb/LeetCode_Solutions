class Solution {
    vector<string> res;
    string num[10];
    void dfs(string digits, int idx, string s){
        if(idx==digits.size()){
            if(s.size()>0)
                res.push_back(s);
            return;
        }
        for(char c : num[digits[idx]-'0']){
            s.push_back(c);
            dfs(digits,idx+1,s);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string s = "";
        num[2]="abc";
        num[3]="def";
        num[4]="ghi";
        num[5]="jkl";
        num[6]="mno";
        num[7]="pqrs";
        num[8]="tuv";
        num[9]="wxyz";
        dfs(digits, 0, s);
        return res;
    }
};