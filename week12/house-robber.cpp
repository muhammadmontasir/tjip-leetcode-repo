// TC: O(N)
// MC: O(N)
class Solution {
public:
    vector<int> cache;
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        cache.clear();
        cache.resize(nums.size(), -1);
        cache[0] = nums[0];
        cache[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            cache[i] = max(nums[i] + cache[i-2], cache[i - 1]);
        }
        return cache[nums.size() - 1];
    }
    /*
    int countGain(int pos, vector<int>&nums) {
        if (pos >= nums.size()) return 0;
        if (cache[pos] != -1) return cache[pos];
        return cache[pos] = max(countGain(pos + 1, nums), nums[pos] + countGain(pos + 2, nums));
    }
    
    int robRec(vector<int>& nums) {
        cache.clear();
        cache.resize(nums.size(), -1);
        return countGain(0, nums);
    }
    */
};