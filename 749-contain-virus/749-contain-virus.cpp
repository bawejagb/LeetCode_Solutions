class Solution {
    set<int> seen;
    vector<set<int>> regions;
    vector<set<int>> frontiers;
    vector<int> perimeters;
    int R,C;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    void dfs(vector<vector<int>>& grid, int r, int c){
        if(seen.find(r*C+c)==seen.end()){
            seen.insert(r*C+c);
            int N = regions.size();
            regions[N-1].insert(r*C+c);
            for(int k=0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];
                if(nr<0||nr==R||nc<0||nc==C) continue;
                if(grid[nr][nc]==1) dfs(grid, nr,nc);
                else if(grid[nr][nc]==0){
                    frontiers[N-1].insert(nr*C+nc);
                    perimeters[N-1]++;
                }
            }
        }
    }
public:
    int containVirus(vector<vector<int>>& isInfected) {
        R = isInfected.size();
        C = isInfected[0].size();
        int ans = 0;
        while(true){
            seen.clear();
            regions.clear();
            frontiers.clear();
            perimeters.clear();
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    if(isInfected[i][j]==1 && seen.find(i*C+j)==seen.end()){
                        regions.push_back(set<int>());
                        frontiers.push_back(set<int>());
                        perimeters.push_back(0);
                        dfs(isInfected,i,j);
                    }
                }
            }
            if(regions.empty())break;
            int idx=0;
            for(int i=0;i<frontiers.size();i++){
                if(frontiers[idx].size()<frontiers[i].size())
                    idx = i;
            }
            ans += perimeters[idx];
            for(int i=0;i<regions.size();i++){
                if(i==idx){
                    for(int code: regions[i])
                        isInfected[code/C][code%C] = -1;
                }
                else{
                    for(int code: regions[i]){
                        int r = code/C, c = code%C;
                        for(int k=0;k<4;k++){
                            int nr = r+dr[k];
                            int nc = c+dc[k];
                            if(nr<0||nr==R||nc<0||nc==C ||isInfected[nr][nc]!=0) continue;
                            isInfected[nr][nc]=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};