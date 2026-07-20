class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Boolean arrays to track numbers 1-9 (1-indexed for convenience)
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool boxes[9][10] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                // Skip empty cells
                if (board[r][c] == '.') {
                    continue;
                }

                int num = board[r][c] - '0';
                int boxIndex = (r / 3) * 3 + (c / 3);

                // Check if the number has already been seen in this row, col, or box
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};