class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //using min heap
        priority_queue<int,vector<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            
        }
        int res;
        while(k--){
            res = pq.top();
            pq.pop();
        }
        return res;
    }
};