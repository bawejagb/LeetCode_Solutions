class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0, n = words.size();
        int arr[n];
        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=0;j<words[i].size();j++)
                cur = cur | 1<<(words[i][j]-'a');
            arr[i] = cur;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((arr[i]&arr[j])==0){
                    int val = words[i].size()*words[j].size();
                    res = max(res,val);
                }
            }
        }
        return res;
    }
};