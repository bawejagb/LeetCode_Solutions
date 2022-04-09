class Solution {
    
    class UnionFind{
        vector<int> rank, root;
        public:
        UnionFind(int size){
            for(int i=0;i<size;i++){
                root.push_back(i);
                rank.push_back(i);
            }
        }
        int find(int x){
            if(root[x] == x) return x;
            return root[x] = find(root[x]);
        }
        void connect(int x, int y){
            int rx = find(x);
            int ry = find(y);
            if(rx==ry) return;
            if(rank[rx]>=rank[ry]){
                root[ry] = rx;
                rank[rx] += rank[ry];
            }
            else{
                root[rx] = ry;
                rank[ry] += rank[rx];
            }
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailGrp;
        unordered_map<int,vector<string>> comp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(emailGrp.find(email)!=emailGrp.end())
                    uf.connect(i,emailGrp[email]);
                else
                    emailGrp[email]= i;
            }
        }
        for(auto item : emailGrp)
            comp[uf.find(item.second)].push_back(item.first);
        for(auto item : comp){
            vector<string> temp = {accounts[item.first][0]};
            temp.insert(temp.end(), item.second.begin(),item.second.end());
            sort(temp.begin()+1,temp.end());
            res.emplace_back(temp);
        }
        return res;
    }
};