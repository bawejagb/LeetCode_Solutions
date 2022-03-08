class Solution {
    int find(vector<int>& nums, int k){
        int n = nums.size();
        int a=0,res=0,cnt=0;
        vector<int> hmap(20002,0);
        for(int i=0;i<n;i++){
            if(hmap[nums[i]]==0) cnt++;
            hmap[nums[i]]++;
            while(cnt>k){
                hmap[nums[a]]--;
                if(hmap[nums[a]]==0) cnt--;  
                a++;
            }
            res += i-a+1; 
            
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k-1);
    }
};