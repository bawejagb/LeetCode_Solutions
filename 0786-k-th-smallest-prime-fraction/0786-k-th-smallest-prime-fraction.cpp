class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return (double)a.first/(double)a.second < (double)b.first/(double)b.second;
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<int,int>> pVec;
        for(int i=1;i<n;i++){
            for(int j = 0; j<i;j++){
                pVec.push_back({arr[j],arr[i]});
            }
        }
        sort(pVec.begin(),pVec.end(), cmp);
        return {pVec[k-1].first,pVec[k-1].second};
    }
};