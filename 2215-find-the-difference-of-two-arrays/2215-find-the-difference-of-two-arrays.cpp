class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1(nums1.begin(),nums1.end()), n2(nums2.begin(),nums2.end());
        vector<int> res1,res2;
        for(int num : n1){
            if(n2.find(num)==n2.end())
                res1.push_back(num);
        }
        for(int num : n2){
            if(n1.find(num)==n1.end())
                res2.push_back(num);
        }
        vector<vector<int>> res = {res1,res2};
        return res;
    }
};