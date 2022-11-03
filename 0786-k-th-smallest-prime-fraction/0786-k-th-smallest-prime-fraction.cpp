class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, r = 1.0;
        while(l<r){
            double m = (l+r)/2;
            double max_f = 0.0;
            int total=0,p=0,q=0;
            int j=1;
            for(int i=0;i<n-1;i++){
                while(j<n && arr[i] > m*arr[j])
                    j++;
                total += (n-j);
                if(j==n)
                    break;
                double f = static_cast<double>(arr[i]) / arr[j];
                if (f > max_f) {
                  p = i;
                  q = j;
                  max_f = f;
                }
            }
            if (total == k)
                return {arr[p], arr[q]}; 
            else if (total > k)
                r = m;
            else
                l = m;
        }
        return {};
    }
};