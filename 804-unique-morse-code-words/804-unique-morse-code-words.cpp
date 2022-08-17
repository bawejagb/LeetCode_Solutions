class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string v[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto x:words)
        {
            string t="";
            for(auto y:x)
                t+=v[y-'a'];
            s.insert(t);
        }
        return s.size();
    }
};