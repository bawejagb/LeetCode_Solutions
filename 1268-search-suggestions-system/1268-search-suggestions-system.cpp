class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
   
     vector<vector<string>> ans;
        sort(products.begin(), products.end());
        string key;
        for(auto c: searchWord){
            key += c;
            auto l=lower_bound(products.begin(), products.end(), key);
            auto r=upper_bound(products.begin(), products.end(), key+='~');
            key.pop_back();
            if(l == r) break;
            ans.emplace_back(l, min(l+3, r));            
        }
        while(ans.size() != searchWord.size()) ans.push_back({});
        return ans; 
    }
};