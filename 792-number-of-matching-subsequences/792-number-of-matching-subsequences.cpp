class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        int pos;
        if (s.empty())
            return 0;
        for (const string& w : words){
            if (w.empty())
                continue;
            pos = 0;
            for (char c : w){
                pos = s.find(c, pos);
                if (pos == string::npos)
                    break;
                pos++;
            }
            if (pos != string::npos)
                count++;
        }
        return count;
    }
};