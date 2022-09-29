class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>> temp(n);
        for(int i=0;i<n;i++)
            temp[i] = {abs(x-arr[i]),arr[i]};
        vector<int> res;
        sort(temp.begin(),temp.end());
        for(int i=0;i<k;i++)
            res.push_back(temp[i].second);
        sort(res.begin(),res.end());
        return res;
    }
};