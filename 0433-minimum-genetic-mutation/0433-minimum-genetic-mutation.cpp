
class Solution {
   bool getDiff(string s1, string s2){
        int count=0;
        for(int i=0;i<8;i++){
            if(s1[i]!= s2[i])
                count++;
        }
        return count==1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>>q;
        q.push({start,0});
        unordered_map<string,bool> mp;
        mp[start]=true;
        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();
            for(string s: bank){
                if(mp.find(s) == mp.end() && getDiff(s,p.first)){
                    if(s == end)
                        return p.second+1;
                    q.push({s,p.second+1});
                    mp[s] = true;
                }
            }
        }
        return -1;
    }
};