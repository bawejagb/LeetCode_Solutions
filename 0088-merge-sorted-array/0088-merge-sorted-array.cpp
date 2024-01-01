class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start_idx1=0;
        int start_idx2=0;
        int res_idx=0;
        vector<int> result(n+m);
        while(start_idx1<m && start_idx2<n){
            if(nums1[start_idx1] <= nums2[start_idx2])
                result[res_idx++] = nums1[start_idx1++];
            else
                result[res_idx++] = nums2[start_idx2++];
        }
        while(start_idx1<m)
            result[res_idx++] = nums1[start_idx1++];
        while(start_idx2<n)
            result[res_idx++] = nums2[start_idx2++];
        nums1 = result;
    }
};