class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pas;
        pas.push_back(1);
        for(int i = 0; i < rowIndex; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<pas.size();j++){
                temp.push_back(pas[j]+pas[j-1]);
            }
            temp.push_back(1);
            pas = temp;
        }
        return pas;
    }
};