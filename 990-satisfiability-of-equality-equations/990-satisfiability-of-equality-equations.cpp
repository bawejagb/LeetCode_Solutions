class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> graph(26);
        int n = equations.size();
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
                int a = equations[i][0]-'a';
                int b = equations[i][3]-'a';
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }
        vector<int> color(26,0);
        int col = 0;
        for(int i=0;i<26;i++){
            if(color[i]==0){
                col++;
                queue<int> qt;
                qt.push(i);
                while(!qt.empty()){
                    int node = qt.front();
                    qt.pop();
                    for(int x : graph[node]){
                        if(color[x]==0){
                            qt.push(x);
                            color[x] = col;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='!'){
                int a = equations[i][0]-'a';
                int b = equations[i][3]-'a';
                if(a==b||color[a]!=0&&color[a]==color[b])
                    return false;
            }
        }
        return true;
    }
};