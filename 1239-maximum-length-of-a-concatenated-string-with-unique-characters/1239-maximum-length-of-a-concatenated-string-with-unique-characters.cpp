class Solution {
    int freq[26]{};
    int res=0;
    void backtrack(vector<string>& arr, int l, int r){
        int cnt = 0;
        for(int i=0;i<26;i++){
            if(freq[i]==1) cnt++;
            if(freq[i]>1) return;
        }
        res = max(res,cnt);
        for(int i=l; i<r;i++){
            for(char c : arr[i])
                freq[c-'a']++;
            backtrack(arr, i+1, r);
            for(char c : arr[i])
                freq[c-'a']--;
        }
    }
public:
    int maxLength(vector<string>& arr) {
        backtrack(arr,0,arr.size());
        return res;
    }
};