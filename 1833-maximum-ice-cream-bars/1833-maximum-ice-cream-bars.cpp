class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(int cst : costs){
            if(cst>coins) break;
            coins -= cst;
            cnt++;
        }
        return cnt;
    }
};