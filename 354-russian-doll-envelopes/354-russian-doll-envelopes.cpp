class Solution {
    static bool cmp(const vector<int> &A, const vector<int> &B){
        return A[0]==B[0]? A[1]>B[1]:A[0]<B[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> res;
        sort(envelopes.begin(),envelopes.end(), cmp);
        res.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(res.back()<envelopes[i][1])
                res.push_back(envelopes[i][1]);
            else{
                int it = lower_bound(res.begin(),res.end(),envelopes[i][1])-res.begin();
                res[it] = envelopes[i][1];
            }
        }
        return res.size();
    }
};