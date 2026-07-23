class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int max_pairs) {
        // Base case: If the current string reaches the max possible length
        if (current.length() == max_pairs * 2) {
            result.push_back(current);
            return;
        }

        // Rule 1: Add an open parenthesis if we still have some left
        if (open < max_pairs) {
            backtrack(result, current + "(", open + 1, close, max_pairs);
        }

        // Rule 2: Add a close parenthesis if it won't violate well-formedness
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max_pairs);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
