class Solution {
    bool checkPalindrome(string w, int left, int right){
        while(left<right){
            if(w[left]!=w[right]) return false;
            left++;
            right--;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        unordered_map<string,int> hmap;
        set<int> lengths;
        for(int i=0;i<n;i++){
            hmap[words[i]]=i;
            lengths.insert(words[i].size());
        }
        for(int i=0;i<n;i++){
            string w = words[i];
            reverse(w.begin(),w.end());
            int len = w.size();
            if(len==1){
                if(hmap.find("")!=hmap.end()){
                    res.push_back({i,hmap[""]});
                    res.push_back({hmap[""],i});
                }
                continue;
            }
            if(hmap.find(w)!=hmap.end() && hmap[w]!=i)
                res.push_back({i,hmap[w]});
            for(int sz : lengths){
                if(sz==len) break;
                if(checkPalindrome(w, 0,len-1-sz)){
                    string s1 = w.substr(len-sz);
                    if(hmap.find(s1)!=hmap.end())
                        res.push_back({i,hmap[s1]});
                }
                if(checkPalindrome(w,sz,len-1)){
                    string s2 = w.substr(0,sz);
                    if(hmap.find(s2)!=hmap.end())
                        res.push_back({hmap[s2],i});
                }
            }
        }
        return res;
    }
};