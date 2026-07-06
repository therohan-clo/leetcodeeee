class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // 1. Sort the input array
        sort(nums.begin(), nums.end());
        
        // 2. Iterate through the array to fix the first element
        for (int i = 0; i < n - 2; i++) {
            // Optimization: If the fixed element is greater than 0, 
            // any elements after it will also be positive and cannot sum to 0.
            if (nums[i] > 0) break;
            
            // Skip duplicate values for the first element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 3. Set up two pointers for the remaining elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers inward for the next check
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // The sum is too small, increase it by moving left pointer right
                } 
                else {
                    right--; // The sum is too large, decrease it by moving right pointer left
                }
            }
        }
        return result;
    }
};
