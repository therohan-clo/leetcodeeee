#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);

        // Step 1: Calculate prefix products and store them in the answer array
        // answer[i] will contain the product of all elements to the left of i
        int left_product = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = left_product;
            left_product *= nums[i];
        }

        // Step 2: Calculate suffix products on the fly and multiply into answer
        // right_product tracks the product of all elements to the right of i
        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= right_product;
            right_product *= nums[i];
        }

        return answer;
    }
};