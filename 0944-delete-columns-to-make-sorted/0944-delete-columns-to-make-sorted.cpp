class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        int n = strs.size(), m = strs[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n-1; j++){
                if(strs[j][i]>strs[j+1][i]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};