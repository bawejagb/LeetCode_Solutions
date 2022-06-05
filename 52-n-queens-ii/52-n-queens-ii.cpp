class Solution {
public:
    int ans = 0;
    void helper(int i, int n, vector<int> & board) {
        if (i == n)
        { ans++; return; }
        for (int j = 1; j <= n; j++) {
            bool ok = true;
            board[i] = j;
            for (int k = 0; ok && k < i; k++) {
                if (board[k] == board [i]) ok = false;
                if (abs(board[k] - board[i]) == abs(k - i))
                    ok = false;
            }
            if (!ok) continue;
            helper(i+1, n, board);
        }
    }
    int totalNQueens(int n) {
        ans = 0;
        vector<int> board(n);
        helper(0, n, board);
        return ans;
    }
};