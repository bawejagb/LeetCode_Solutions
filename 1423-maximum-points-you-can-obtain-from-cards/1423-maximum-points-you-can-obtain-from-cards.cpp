class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mxsum, sum, n = cardPoints.size();
        sum = 0;
        for(int i=0;i<k;i++)
            sum += cardPoints[i];
        mxsum = sum;
        for(int i=0;i<k;i++){
            sum += cardPoints[n-i-1] - cardPoints[k-i-1];
            if(sum > mxsum)
                mxsum = sum;
        }
        return mxsum;
    }
};