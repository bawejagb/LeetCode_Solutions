class Solution {
public:
    void mergeSort(vector<pair<int,int>>&v, vector<int>&count, int l, int m , int r){
        vector<pair<int,int>>t(r-l+1);
        int i = l, j = m+1, k = 0;
        while(i <= m && j <= r){
            if(v[i].first > v[j].first){
                count[v[i].second] += r-j+1;
                t[k] = v[i];
                i++;
            }
            else{
                t[k] = v[j];
                j++;
            }
            k++;
        }
        while(i <= m){
            t[k++] = v[i++];
        }
        while(j <= r){
            t[k++] = v[j++];
        }
        for(int it = l; it <= r; it++){
            v[it] = t[it-l];
        }
    }
    
    void solve(vector<pair<int,int>>&v, vector<int>&count, int l, int r){
        if(l < r){
            int m = l+(r-l)/2;
            solve(v, count, l, m);
            solve(v, count, m+1, r);
            mergeSort(v, count,l , m , r);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>count(n,0);
        vector<pair<int,int>>num;
        for(int i = 0; i < n; i++){
            num.push_back({nums[i],i});
        }
        solve(num,count,0,n-1);
        return count;
    }
};