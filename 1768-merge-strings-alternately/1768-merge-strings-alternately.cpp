class Solution {
public:
    string mergeAlternately(string a, string b) {
        int n=(int)a.size()+(int)b.size();
        vector<char> s(n);
        int i=1,x=0,c=0,d=0;
        while(i<=n){
            if(c<(int)a.size()){
                s[i-1]=a[c];
                c++;i++;
            }
            if(d<(int)b.size()){
                s[i-1]=b[d];
                d++;i++;
            }
        }
        string ans="";
      for(auto x:s)
        ans+=x;
      return ans;
    }
};