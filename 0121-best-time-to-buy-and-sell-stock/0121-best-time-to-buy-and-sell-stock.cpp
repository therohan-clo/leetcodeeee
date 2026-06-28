#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // If there are no prices or only 1 day, no profit can be made
        if (prices.size() <= 1) {
            return 0;
        }

        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum price seen so far
            min_price = std::min(min_price, prices[i]);

            // Calculate profit if sold today and update max_profit if it's higher
            int current_profit = prices[i] - min_price;
            max_profit = std::max(max_profit, current_profit);
        }

        return max_profit;
    }
};