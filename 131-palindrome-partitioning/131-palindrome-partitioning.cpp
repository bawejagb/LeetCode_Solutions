class Solution {
    vector<vector<string>> res;
    bool isPalindrome(string s,int start, int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void backtrack(int idx, string s, vector<string> &path){
        if(idx==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                backtrack(i+1,s,path);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(0,s,path);
        return res;
    }
};