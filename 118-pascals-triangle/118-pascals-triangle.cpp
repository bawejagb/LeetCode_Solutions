class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1; j < i; j++){
                temp.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            if(i > 0)
                temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};