class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double prefix = 1;
        double suffix = 1;
        double maxProd = INT_MIN;

        for (int i = 0; i < n; i++) {
            // If prefix or suffix becomes 0, reset them to 1 (handling the 0 boundary)
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            // Calculate prefix from the left, suffix from the right
            prefix *= nums[i];
            suffix *= nums[n - 1 - i];

            // Keep track of the maximum product seen so far
            maxProd = max(maxProd, max(prefix, suffix));
        }

        return static_cast<int>(maxProd);
    }
};