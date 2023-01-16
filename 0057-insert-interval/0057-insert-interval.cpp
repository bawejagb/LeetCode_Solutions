class Solution {
public:
    bool hasOverlap(vector <int> &i1, vector <int> &i2) {
       return i2[0] <= i1[1];    
    }
  
    vector <int> merge(vector <int> &i1, vector <int> &i2) {
      return { min(i1[0], i2[0]), max(i1[1], i2[1]) };
    }
  
    void check(vector <vector<int>> &aux, vector <int> &curr) {
      if(!aux.empty() and hasOverlap(aux.back(), curr)) {
          vector <int> prev = aux.back();

          aux.pop_back();
          aux.push_back(merge(prev, curr));
        }
        else {
          aux.push_back(curr);
        }
    }
  
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        vector <vector<int>> aux;
        for(int i = 0; i < idx; i++) 
          check(aux, intervals[i]);
        check(aux, newInterval);
        for(int i = idx; i < intervals.size(); i++) 
          check(aux, intervals[i]);
        return aux;
    }
};