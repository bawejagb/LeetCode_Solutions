class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
            time[i] = time[i]%60;
        long hmap[60]{};
        for(int i = 0;  i< n; i++)
            hmap[time[i]]++;
        for(int i = 0; i <= 30; i++){
            if(hmap[i] == 0) continue;
            if(i == 0 || i == 30) cnt += (hmap[i]*(hmap[i]-1)/2);
            else cnt +=(hmap[i]*hmap[60-i]); 
        }
        return cnt;
    }
};