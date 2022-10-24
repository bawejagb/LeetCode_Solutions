class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        nth_element(A.begin(), A.begin()+k-1, A.end(), greater<int> ());
        return A[k-1];
    }
};