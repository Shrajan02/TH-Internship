class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        if (open == n && close == n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(result, current + '(', open + 1, close, n);
        }
        if (close < open) {
            backtrack(result, current + ')', open, close + 1, n);
        }
    }
};