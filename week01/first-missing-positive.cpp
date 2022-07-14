class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> bucket(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size() + 1; i++) {
            if (bucket.count(i) == 0) return i;
        }
        return 0;
    }
};