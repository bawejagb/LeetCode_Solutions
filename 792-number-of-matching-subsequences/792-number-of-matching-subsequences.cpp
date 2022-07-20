class Solution {
public:
    bool check(string s,string t){
        int i=0;
        int j=0;
        while(i<s.length() and j<t.length()){
          if(s.length()-i < t.length()-j) return false;
            if(s[i]==t[j]) j++;
            i++;
        }
        return (j==t.length());
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        unordered_map<string,int> m;
        for(auto word : words){
            if(m[word]==1) count++;
            else if(m[word]==-1) continue;
            else{
                if(check(s,word)) m[word]=1,count++;
                else m[word]=-1;
            }
            
        }
        return count;
    }
};