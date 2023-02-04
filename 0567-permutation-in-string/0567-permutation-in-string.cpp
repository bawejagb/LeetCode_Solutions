class Solution {
public:
     bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        sort(begin(s1),end(s1));
        for(int i=0;i<m-n+1;i++){
            string temp=s2.substr(i,n);
            sort(temp.begin(),temp.end());
            if(s1==temp)return true;
        }
        return false;
    }
};