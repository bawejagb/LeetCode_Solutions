class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt=0;
        string temp = strs[0];
        int len = temp.size();
        bool mark[1001]{};
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<len;j++){
                if(strs[i][j]<temp[j])
                    mark[j]=true;
            }
            temp = strs[i];
        }
        for(int i=0;i<len;i++)
            if(mark[i]) cnt++;
        return cnt;
    }
};