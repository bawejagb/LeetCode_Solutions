class Solution {
public:
    int totalStrength(vector<int>& strength) {
        using ll = long long;
        ll MOD = 1e9+7;
        int N = strength.size();
        ll prefix[N+1];
        prefix[0] = 0;
        for(int i=0;i<N;i++)
            prefix[i+1] = (prefix[i]+strength[i])%MOD;
        ll prePrefix[N+2];
        prePrefix[0] = 0;
        for(int i=0;i<=N;i++)
            prePrefix[i+1] = (prePrefix[i]+prefix[i])%MOD;
        ll left[N],right[N];
        stack<ll> st;
        for(int i=0;i<N;i++){
            while(!st.empty() and strength[st.top()]>=strength[i])
                st.pop();
            left[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=N-1;i>=0;i--){
            while(!st.empty() and strength[st.top()]>strength[i])
                st.pop();
            right[i] = st.empty() ? N: st.top();
            st.push(i);
        }
        ll res = 0;
        for(int i=0;i<N;i++){
            res += ((prePrefix[right[i]+1]-prePrefix[i+1])*(i-left[i])%MOD+MOD*2-(prePrefix[i+1]-prePrefix[left[i]+1])*(right[i]-i)%MOD)%MOD*strength[i]%MOD;
            res %= MOD;
        }
        return (int) res;
    }
};