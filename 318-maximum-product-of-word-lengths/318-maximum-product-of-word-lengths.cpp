class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0, n = words.size();
        int arr[n];
        for(int i=0;i<n;i++){
            int cur=0;
            for(char c : words[i])
                cur = cur | 1<<(c -'a');
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