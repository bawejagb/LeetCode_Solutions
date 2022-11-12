class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, vector<int>> map;
        for(int i = 1 ; i <= 7 ; i++){
            int prev = cells[0];
            for(int i = 1 ; i < 7 ; i++){
                int temp = cells[i];
                cells[i] = !(prev^cells[i+1]);
                prev = temp;
            }
            cells[0] = 0;
            cells[7] = 0;
            map[i] = cells;
        }
        
        double temp = ceil(n/7.0);
        int evenOdd = temp;
        if(evenOdd%2 == 0){
            n%=7;
            if(n == 0)
                n = 7;
            reverse(map[n].begin(), map[n].end());
            return map[n];
        }else{
            n%=7;
            if(n == 0)
                n = 7;
            return map[n];
        }
    }
};