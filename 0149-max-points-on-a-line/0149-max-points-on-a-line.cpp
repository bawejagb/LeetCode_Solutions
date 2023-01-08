class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        vector<double> s;
        int ans = 0, c = 0, f = 0, u = 0;
        int n = points.size(); 
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                double y = points[i][1] - points[j][1];
                double x = points[i][0] - points[j][0];
                if(x == 0 || y == 0){
                    if(x == 0)
                        f++;
                    
                    if(y == 0)
                        u++;
                }
                else
                    s.push_back(y / x);
            }
            sort(s.begin(),s.end());
            for(int j = 1; j < s.size(); j++){
                if(s[j] == s[j - 1])
                    c++;
                else{
                    if(c + 1 > ans)
                        ans = c + 1;
                    c = 0;
                }
            }
            if(c + 1 > ans)
                ans = c + 1;
            c = 0;
            if(f > ans)
                ans = f;
            if(u > ans)
                ans = u;
            s.clear();
            f = 0;
            u = 0;
        }
        return ans + 1;
    }
};