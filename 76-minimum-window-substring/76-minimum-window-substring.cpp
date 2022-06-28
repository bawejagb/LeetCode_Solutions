class Solution {
public:
    
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i,j,start,end;
        map<char,int> mp;
        for(auto it: t){
            mp[it]++;
        }
        int curr=0,ans=n+1;
        i=0,j=0;
        while (j<n){
            if (mp[s[j]]>0){
                curr++;
            }
            
            mp[s[j]]--;
            
            if (curr==m){
                while (i<j && mp[s[i]]<0){
                    mp[s[i]]++;
                    i++;
                }
                
                if (ans>j-i+1){
                    start=i;
                    end=j;
                    ans=j-i+1;
                }
                
                mp[s[i]]++;
                i++;
                curr--;
            }
            
            j++;
        }
        
        if (ans==n+1){
            return "";
        }
        else{
            return s.substr(start,ans);
        }
        
    }
    
};