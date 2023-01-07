class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int b,bal,n=cost.size();
        bal=0;
        b=0;
        bool fg=0;
        for(int i=0;i<n;i++)
            bal += (gas[i]-cost[i]);
        if(bal<0) return -1;
        bal=0;
        for(int i=0;i<n;i++){
            bal +=(gas[i]-cost[i]);
            if(bal<0){
                bal=0;
                b=i+1;
            }
        }
        return b%n;
    }
};