class Solution {
    map<int,int> deg;

public:
    int findJudge(int n, vector<vector<int>>& trust) {
      if(trust.size()  == 0 && n==1) return 1;
        for(int i = 0; i < trust.size(); i++){
          deg[trust[i][1]]++;
          deg[trust[i][0]]--;
      }
        for(auto x : deg){
            if( x.second == n-1)
                return x.first;
        }
        return -1;
    }
};