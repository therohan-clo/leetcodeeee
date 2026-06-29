class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for(int i = 0; i < nums.size(); i++) {
            if(seen.count(nums[i])) {
                return true;  // Found duplicate
            }
            seen.insert(nums[i]);
        }
        return false;  // No duplicates
    }
};