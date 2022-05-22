class Solution
{
    public:
        int countSubstrings(string s)
        {
            int count = 0;
            int left, right, n;
            n = s.size();
            for (int i = 0; i < n; i++)
            {
                left = right = i;
                while (left >= 0 && right < n && s[left] == s[right])
                    count++, left--, right++;
                
                left = i - 1, right = i;
                while (left >= 0 && right < n && s[left] == s[right])
                    count++, left--, right++;
            }
            return count;
        }
};