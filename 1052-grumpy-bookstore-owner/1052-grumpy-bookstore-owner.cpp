class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        
        int ans=0,sa=0,add_sa=0;
        
        for( int i=0;i< c.size();i++){
            
            if( !g[i]) sa+=c[i];
            
            add_sa += g[i]*c[i];
            
            if( i>=m) add_sa -= g[i-m]*c[i-m];
            
            ans=max( ans, add_sa);
        }
        return ans+sa;
    }
};