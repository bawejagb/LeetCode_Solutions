class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
         priority_queue<int> q;
         long long f=startFuel,ans=0;
         for(int i=0;i<s.size();i++){
             if(f>=s[i][0]){
                 q.push(s[i][1]);
             }
             else{
                 ans++;
                 if(q.empty()){
                    return -1;
                 }
                 else{
                     f+=q.top();
                     q.pop();
                     i--;
                 }
             }
         }
         while(f<target&&!q.empty()){
             f+=q.top();
             q.pop();
             ans++;
         }
        return f>=target?ans:-1;
    }
};