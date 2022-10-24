class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        map<char,int> hmap;
        int mx=0;
        char ch;
        for(char c: s){
            hmap[c]++;
            if(hmap[c]>mx){
                mx = hmap[c];
                ch = c;
            }
        }
        if(mx > (n+1)/2) return "";
        int i=0;
        while(mx--){
            s[i] = ch;
            i += 2;
        }
        hmap.erase(ch);
        for(auto it : hmap){
            char c = it.first;
            int fq = it.second;
            while(fq--){
                if(i>=n) i = 1;
                s[i] = c;
                i += 2;
            }
        }
        return s;
    }
};