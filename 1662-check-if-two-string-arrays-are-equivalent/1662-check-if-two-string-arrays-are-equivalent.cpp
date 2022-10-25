class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n,m,i=0,j=0;
        m = word2.size();
        n = word2[0].size();
        for(string word: word1){
            for(char c : word){
                if(i+1<m && j==n){
                    j=0;
                    i++;
                    n = word2[i].size();
                }
                if(i<m && j < n && c == word2[i][j]){
                    j++;
                }
                else return false;
            }
        }
        return (j==n && i == m-1);
    }
};