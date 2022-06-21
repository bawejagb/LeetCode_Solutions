
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int smallest;
        priority_queue<int, vector<int>, greater<int>> ladder_used;
        if(ladders == 0)
            ladder_used.push(INT_MAX);
        
        for(int i = 1;i<heights.size();i++)
        {
            int diff = heights[i]-heights[i-1];
            if(diff>0)
            {
                if(!ladder_used.empty())
                    smallest = ladder_used.top();
                if(ladders!=0)
                {
                    ladder_used.push(diff);
                    ladders--;
                }
                else if(diff > smallest)
                {
                    if(bricks < smallest)
                        return i-1;
                    bricks-=smallest;
                    ladder_used.pop();
                    ladder_used.push(diff);
                }
                else
                {
                    if(bricks < diff)
                        return i-1;
                    bricks-=diff;
                }
            }
        }
        
        return heights.size()-1;
    }
};