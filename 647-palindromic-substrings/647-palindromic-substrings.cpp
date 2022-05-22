class Solution
{
    public:
        int countSubstrings(string s)
        {
            int count = 0;
            int left, right;
            for (int i = 0; i < s.size(); i++)
            {
                left = right = i;
                while (left >= 0 && right < s.size() && s[left] == s[right])
                    count++, left--, right++;

                left = i - 1, right = i;
                while (left >= 0 && right < s.size() && s[left] == s[right])
                    count++, left--, right++;
            }
            return count;
        }
};