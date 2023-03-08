class Solution {
    bool check(vector<int>&piles, long h, long mid){
        long cnt = 0;
        for(int val : piles){
            if(val%mid>0) cnt++;
            cnt += val/mid;
        }
        return (cnt <= h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid, left=1, right=1;
        for(int val : piles)
            right = max(right, val);
        while(left<=right){
            mid = left + (right-left)/2;
            if(check(piles,h,mid))
                right = mid-1;
            else
                left = mid+1;
        }
        return right+1;
    }
};