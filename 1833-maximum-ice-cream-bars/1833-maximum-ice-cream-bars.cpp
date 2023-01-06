class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mxVal=0;
        int cnt=0;
        int hmap[100005]{};
        for(int cst : costs){
            mxVal = max(cst, mxVal);
            hmap[cst]++;
        }
        for(int i=1;i<=mxVal;i++){
            if(hmap[i]==0) continue;
            if(i>coins) break;
            int mn = min(hmap[i],coins/i);
            coins -= mn*i;
            cnt += mn;
        }
        return cnt;
    }
};