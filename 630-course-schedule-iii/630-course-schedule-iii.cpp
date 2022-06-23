class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        if (n <= 0)
            return 0;
        
        sort(courses.begin(), courses.end(), [](vector<int> &v1, vector<int> &v2){
           return v1[1] < v2[1]; 
        });
        
        int totalTime = 0;
        priority_queue<int> pq;
        for (auto c: courses)
        {
            totalTime += c[0];
            pq.push(c[0]);
            
            if (totalTime > c[1])
            {
                int longestDur = pq.top();
                pq.pop();
                
                totalTime -= longestDur;
            }
        }
        return pq.size();
    }
};