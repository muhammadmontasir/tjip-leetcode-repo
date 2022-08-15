// TC: O(N^2)
// MC: O(N)

class Solution {
public:
    vector<int>cache;
    int suffixLIS(int pos, vector<int>& nums) {
        if (pos >= nums.size()) return 0;
        if (cache[pos] != -1) return cache[pos]; // DP
        int lis = 1; // pos initialized
        for (int i = pos + 1; i<nums.size(); i++) {
            if (nums[pos] < nums[i]) {
                lis = max(lis, 1 + suffixLIS(i, nums));
            }
        }
        return cache[pos] = lis;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), LIS = -1;
        cache.clear();
        cache.resize(n, -1);
        for (int i = 0; i < n; i++) {
            LIS = max(LIS, suffixLIS(i, nums));
        }
        return LIS;
        
        /*
        int n = nums.size(), LIS = 1;
        vector<int> cache(n, 1);
        for (int i = n-2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    cache[i] = max(cache[i], cache[j] + 1);
                    LIS = max(LIS, cache[i]);
                }
            }
        }
        return LIS;
        */
    }
};