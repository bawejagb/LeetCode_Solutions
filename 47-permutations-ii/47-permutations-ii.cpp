class Solution
{

    void nextPermutation(vector<int> &vec)
    {
        int n = vec.size();
        if (n == 1) return;
        int breakPoint = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (vec[i] < vec[i + 1])
            {
                breakPoint = i;
                break;
            }
        }
        if (breakPoint == -1)
        {
            reverse(vec.begin(), vec.end());
            return;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (vec[i] > vec[breakPoint])
            {
                swap(vec[i], vec[breakPoint]);
                break;
            }
        }
        reverse(vec.begin() + breakPoint + 1, vec.end());
    }
    public:
        vector<vector < int>> permuteUnique(vector<int> &nums)
        {
            vector<int> vec(nums);
            vector<vector < int>> res;
            do {
                res.push_back(vec);
                nextPermutation(vec);
            }
            while (vec != nums);
            return res;
        }
};