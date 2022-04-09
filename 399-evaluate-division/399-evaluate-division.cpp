class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvar = 0;
        unordered_map<string,int> vars;
        for(int i = 0;i<equations.size();i++){
            string va = equations[i][0], vb = equations[i][1];
            if(vars.count(va) == 0)
                vars[va] = nvar++;
            if(vars.count(vb) == 0)
                vars[vb] = nvar++;           
        }
        vector<vector<pair<int,double>>> edges(nvar);
        for(int i = 0;i<equations.size();i++){
            int va = vars[equations[i][0]], vb = vars[equations[i][1]];
            edges[va].push_back({vb,values[i]});
            edges[vb].push_back({va,1.0/values[i]});            
        }
        vector<double> ret;
        for(auto q : queries){
            double result = -1.0;
            if(vars.count(q[0]) && vars.count(q[1])){
                int ia = vars[q[0]], ib = vars[q[1]];
                if(ia == ib)
                    result = 1;
                else{
                    queue<int> que;
                    que.push(ia);
                    vector<double> ratio(nvar,-1);
                    ratio[ia] = 1;
                    while(!que.empty() && ratio[ib] == -1)
                    {
                        int x = que.front();que.pop();
                        for(auto [y,val] : edges[x])
                        {
                            if(ratio[y] == -1)
                            {
                                ratio[y] = ratio[x] * val;
                                que.push(y);
                            }
                        }       
                    }
                    result = ratio[ib];
                }
            }
            ret.push_back(result);            
        }
        return ret;
    }
};