class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        map<char,int>mp;
        vector<string>ans;
        for(auto it:words2)
        {
            map<char,int>curr;
            for(auto itt:it)
            {
                curr[itt]++;
            }
            
            for(auto it:curr)
            {
                mp[it.first]=max(mp[it.first],curr[it.first]);
            }
        }
        
        for(auto it:words1)
        {
            bool take=true;
            map<char,int>temp=mp;
            for(int i=0;i<it.size();i++)
            {
                if(temp[it[i]])
                temp[it[i]]--;
            }
            
            for(auto it:temp)
            {
                if(it.second)
                    take=false;
            }
            
            if(take==true)
                ans.push_back(it);
        }
        return ans;      
    }
};