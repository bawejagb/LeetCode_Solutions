class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int occ[2002]={0};
        for(int x : arr)
            occ[x+1000]++;
        bool unq[1001]={false};
        for(int i=0;i<2002;i++){
            if(occ[i]>0 and unq[occ[i]]) return false;
            unq[occ[i]] = true;
        }
        return true;
    }
};