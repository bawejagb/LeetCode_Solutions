class Solution {
    static bool cmp2(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(), cmp2);
        int maxDef = 0, ans = 0;
        for(int i= properties.size()-1; i >=0; i--){
            if(maxDef > properties[i][1])
                ans++;
            maxDef = max(maxDef, properties[i][1]);
        }
        return ans;
    }
};