class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> count(s.length(), 0);
        int opidx = 0;
        for (int i = 0; i < s.length(); i++, opidx++)
        {
            s[opidx] = s[i];
            if (opidx > 0 && s[opidx] == s[opidx-1])
            {
                count[opidx] = count[opidx-1] + 1;
            }
            else count[opidx] = 1;
            
            if (count[opidx] == k) opidx = opidx - k;
        }
        return s.substr(0, opidx);
    }
};