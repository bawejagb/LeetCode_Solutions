class Solution {
    vector<int> find(vector<int>& nums, int k){
        if(nums.size()<k) return {};
        vector<int> res;
        stack<int> st;
        int rem = k, n = nums.size();
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(nums[i]), rem--;
            else{
                int avail = n-i;
                while(!st.empty() and st.top()<nums[i] and avail > rem) st.pop(), rem++;
                st.push(nums[i]);
                rem--;
            }
        }
        while(st.size()>k) st.pop();
        while(!st.empty()) res.push_back(st.top()), st.pop();
        reverse(res.begin(), res.end());
        return res;
    }
    
    void merge(vector<int>&a, vector<int>&b, vector<int>&res){
        int i = 0, j = 0;
        while(i < a.size() and j < b.size()){
            if(a[i]==b[j]){
                int ti = i, tj = j;
                while(ti < a.size() and tj < b.size() and a[ti]==b[tj]) ti++, tj++;
                if(tj==b.size()) res.push_back(a[i]), i++;
                else
                if(ti<a.size() and a[ti]>b[tj]) res.push_back(a[i]), i++;
                else res.push_back(b[j]), j++;
            }
            else
            if(a[i]>b[j]) res.push_back(a[i]),i++;
            else res.push_back(b[j]), j++;
        }
        while(i < a.size()) res.push_back(a[i]), i++;
        while(j < b.size()) res.push_back(b[j]), j++;
    }
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        for(int i=0;i<=k;i++){
            vector<int> a = find(nums1, i);
            vector<int> b = find(nums2,k-i);
            vector<int> m;
            merge(a,b,m);
            if(m.size()==k)
                res = max(res, m);
        }
        return res;
    }
};