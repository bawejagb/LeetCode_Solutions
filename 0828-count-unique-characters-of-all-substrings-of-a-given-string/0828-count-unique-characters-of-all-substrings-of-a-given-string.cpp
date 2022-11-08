class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> prev(26,vector<int>(2,-1));
        int ans = 0;
        for(int i=0; i<n; i++){
            int x = s[i]-'A';
            ans += (i-prev[x][1])*(prev[x][1]-prev[x][0]);
            prev[x][0] = prev[x][1];
            prev[x][1] = i;
        }
        // this loop calculates taking next index at n
        for(int i=0; i<26; i++){
            ans += (n-prev[i][1])*(prev[i][1]-prev[i][0]);
        }
        return ans;
    }
};