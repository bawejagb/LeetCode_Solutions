class Solution {
    static bool cmp(const vector<int> &A, const vector<int> &B){
        return A[0]==B[0]? A[1]>B[1]:A[0]<B[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> res;
        sort(envelopes.begin(),envelopes.end(), cmp);
        for(int i=0;i<n;i++){
            auto it = lower_bound(res.begin(),res.end(),envelopes[i][1]);
            if(it==res.end()) 
                res.push_back(envelopes[i][1]);
            else    
                *it = envelopes[i][1];
        }
        return res.size();
    }
};