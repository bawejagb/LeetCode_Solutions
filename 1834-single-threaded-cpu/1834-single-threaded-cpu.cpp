class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> nextTask;
        vector<array<int,3>> sortedTask;
        for(int i=0;i<tasks.size();i++)
            sortedTask.push_back({tasks[i][0],tasks[i][1],i});
        sort(sortedTask.begin(),sortedTask.end());
        long time = 0;
        int idx = 0;
        while(idx<tasks.size() or !nextTask.empty()){
            if(nextTask.empty() and time < sortedTask[idx][0])
                time = sortedTask[idx][0];
            while(idx<tasks.size() and time>=sortedTask[idx][0]){
                nextTask.push({sortedTask[idx][1],sortedTask[idx][2]});
                ++idx;
            }
            auto [pTime,tIdx] = nextTask.top();
            nextTask.pop();
            time += pTime;
            res.push_back(tIdx);
        }
        return res;
    }
};