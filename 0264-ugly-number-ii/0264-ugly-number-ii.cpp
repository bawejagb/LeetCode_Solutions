class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        int two=0, three=0, five=0;
        res.push_back(1);
        while(res.size()<n){
            int val2 = res[two]*2;
            int val3 = res[three]*3;
            int val5 = res[five]*5;
            int minVal = min({val2,val3,val5});
            if(minVal==val2) two++;
            else if(minVal==val3) three++;
            else five++;
            if(minVal==res.back()) continue;
            res.push_back(minVal);
        }
        return res.back();
    }
};