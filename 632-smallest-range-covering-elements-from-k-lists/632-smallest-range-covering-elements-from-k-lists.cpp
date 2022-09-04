class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                arr.push_back({nums[i][j],i});
            }
        }
        sort(arr.begin(),arr.end());
        int minVal = -100001, maxVal = 100001;
        int target = nums.size();
        unordered_map<int,int> freq;
        int start=0, end=0;
        while(end<arr.size()){
            while(end<arr.size() && freq.size()<target){
                freq[arr[end].second]++;
                end++;
            }
            while(start <= end-1 && freq.size() == target){
                if(freq.size() == target){
                    if(end>0 && arr[end-1].first-arr[start].first < maxVal-minVal){
                        minVal = arr[start].first;
                        maxVal = arr[end-1].first;
                    }
                }
                freq[arr[start].second]--;
                if(freq[arr[start].second]==0)
                    freq.erase(arr[start].second);
                start++;
            }
        }
        return {minVal,maxVal};
    }
};