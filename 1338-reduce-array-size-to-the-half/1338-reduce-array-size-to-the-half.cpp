class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
         int ans[100001]{};
        for(auto it : arr)
            ans[it]++;
        sort(ans , ans+100001, greater<int>());
        int reqsize = arr.size();
        int i =0;
        while(n/2<reqsize)
            reqsize -= ans[i++];
        return i;
    }
};