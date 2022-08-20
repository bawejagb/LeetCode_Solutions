class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pQueue;
        int refillCount=0;
        int N = stations.size();
        int idx= 0;
        int distanceCovered = startFuel;
        while(distanceCovered < target){
            while(idx < N && stations[idx][0] <= distanceCovered){
                pQueue.push(stations[idx][1]);
                idx++;
            }
            if(pQueue.empty()) return -1;
            distanceCovered += pQueue.top();
            pQueue.pop();
            refillCount++;
        }
        return refillCount;
    }
};