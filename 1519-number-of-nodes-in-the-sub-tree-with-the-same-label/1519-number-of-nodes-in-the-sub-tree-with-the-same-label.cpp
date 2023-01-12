class Solution {
    void dfsCountAndUpdate(int node, int prevNode, vector<vector<int>>& adjVec,
                           string& labels, vector<int>& solution, vector<int>& freqMap) {
        int prevCount = freqMap[labels[node] - 'a'];
        freqMap[labels[node] - 'a'] += 1;
        for (int nextNode : adjVec[node]) {
            if (prevNode == nextNode) continue;
            dfsCountAndUpdate(nextNode, node, adjVec, labels, solution, freqMap);
        }
        solution[node] = freqMap[labels[node] - 'a'] - prevCount;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjVec(n);
        vector<int> solution(n, 0);
        vector<int> freqMap(26, 0);
        for (vector<int>& edge : edges) {
            adjVec[edge[0]].push_back(edge[1]);
            adjVec[edge[1]].push_back(edge[0]);
        }
        dfsCountAndUpdate(0, 0, adjVec, labels, solution, freqMap);
        return solution;
    }
};