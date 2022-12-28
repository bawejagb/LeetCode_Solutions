class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> qt;
        int res=0;
        for(int val : piles)
            qt.push(val);
        while(k--){
            int val = qt.top();
            qt.pop();
            qt.push(val-val/2);
        }
        while(!qt.empty()){
            res += qt.top();
            qt.pop();
        }
        return res;
    }
};