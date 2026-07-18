class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes.
        // Also, if the last digit is 0, the first digit must be 0 (only 0 itself satisfies this).
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        // Reconstruct only the second half of the number
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // For even length digits: x == revertedNumber
        // For odd length digits: x == revertedNumber / 10 (removes the middle digit)
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
