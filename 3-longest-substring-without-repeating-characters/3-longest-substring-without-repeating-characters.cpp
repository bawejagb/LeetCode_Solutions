class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int track[256] {};
            int left = 0, res = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (track[s[i]] > left)
                    left = track[s[i]];
                
                track[s[i]] = i + 1;
                res = max(res, i - left + 1);
            }
            return res;
        }
};