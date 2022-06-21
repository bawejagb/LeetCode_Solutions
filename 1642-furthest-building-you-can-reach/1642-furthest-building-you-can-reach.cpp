class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> qt;
        for(int i = 1; i < n; i++){
            int dif = heights[i]-heights[i-1];
            if(dif <= 0) continue;
            qt.push(dif);
            if(bricks<dif){
                if(ladders==0) return i-1;
                bricks += qt.top();
                qt.pop();
                ladders--;
            }
            bricks -= dif;
        }
        return n-1;
    }
};