class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> new_num;
        int a,b;
        a = b = 0;
        while(a < m && b < n){
            if(nums1[a] < nums2[b]){
                new_num.push_back(nums1[a]);
                a++;
            }
            else{
                new_num.push_back(nums2[b]);
                b++;
            }
        }
        while(a < m){
            new_num.push_back(nums1[a]);
            a++;
        }
        while(b < n){
            new_num.push_back(nums2[b]);
            b++;
        }
        nums1 = new_num;
    }
};