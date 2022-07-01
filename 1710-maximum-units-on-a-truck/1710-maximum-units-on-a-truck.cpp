class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[] (vector<int>&a,vector<int>&b){return a[1]>b[1];});
        int total=0;
        for(int i = 0;truckSize>0 && i<boxTypes.size();i++){
            cout << boxTypes[i][0] << ' ';
            int mn = min(truckSize,boxTypes[i][0]);
            total += mn*boxTypes[i][1];
            truckSize -= mn;
        }
        return total;
    }
};