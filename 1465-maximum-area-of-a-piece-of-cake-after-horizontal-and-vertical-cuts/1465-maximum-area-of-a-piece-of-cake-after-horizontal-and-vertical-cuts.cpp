class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int a,b,mod = 1e9 + 7;
        long long int res = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        a = horizontalCuts[0];
        for(int i = 1; i < horizontalCuts.size(); i++){
            a = max(horizontalCuts[i]-horizontalCuts[i-1],a);
        }
        a = max(h-horizontalCuts.back(),a);
        b = verticalCuts[0];
        for(int i = 1; i < verticalCuts.size(); i++){
            b = max(verticalCuts[i]-verticalCuts[i-1],b);
        }
        b = max(w-verticalCuts.back(),b);
        res = (1ll*a)*b;
        return (int)(res%mod);
    }
};