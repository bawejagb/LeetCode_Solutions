class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int tsum, csum, n;
        n = cardPoints.size();
        tsum = csum = 0;
        for(int i = 0;  i < n ;i++)
            tsum +=cardPoints[i];
        if(n==k) return tsum;
        for(int i = 0;  i < n-k; i++)
            csum += cardPoints[i];
        int res = 0;
        res = tsum-csum;
        int t = 0;
        for(int i = n-k; i < n; i++){
            csum += cardPoints[i];
            csum -= cardPoints[t];
            t++;
            res = max(res,tsum-csum);
        }
        return res;
    }
};