class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long Ans = 0;
        long mx = 1e9 + 7;
        unordered_map<int, long> SubTree;
        
        for (int num: arr) {
            long ways = 1;
            double lim = sqrt(num);
            for (int i=0, childA = arr[0]; childA<=lim; childA = arr[++i]) {
                if (num % childA != 0)
                    continue;
                int childB = num/childA;
                if (SubTree.find(childB) != SubTree.end())
                    ways = (ways + SubTree[childA]*SubTree[childB]*(childA == childB? 1:2) % mx);
            }
            SubTree[num] = ways;
            Ans = (Ans + ways) % mx;
        }
        
        return (int)Ans;
    }
};