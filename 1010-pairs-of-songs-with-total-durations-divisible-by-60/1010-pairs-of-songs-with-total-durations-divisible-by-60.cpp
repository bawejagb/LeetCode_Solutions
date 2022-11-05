class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        for(int i=0;i<n;i++)
            time[i] %= 60;
        int res=0;
        map<int,int> hmap;
        for(int i= 0;i<n;i++){
            if(hmap[(60-time[i])%60]>0){
                res += hmap[(60-time[i])%60];
            }
            hmap[time[i]]++;
        }
        return res;
    }
};