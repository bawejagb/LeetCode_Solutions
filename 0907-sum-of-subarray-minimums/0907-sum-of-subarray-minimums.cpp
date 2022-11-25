class Solution {
    int MOD = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int n = arr.size();
        stack<int> st1,st2;
        vector<int> next(n),prev(n);
        for(int i = 0; i < n; i++){
            prev[i]=-1;
            next[i]=n;
        }
        for(int i=0;i<n;i++){
            while(!st1.empty()&&arr[st1.top()]>arr[i]){
                next[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st2.empty()&&arr[st2.top()]>=arr[i]){
                prev[st2.top()]=i;
                st2.pop();
            }
            st2.push(i);
        }
        for(int i=0;i<n;i++){
            sum = (sum+(1ll*arr[i]*(i-prev[i])*(next[i]-i))%MOD)%MOD;
        }
        return sum;
    }
};