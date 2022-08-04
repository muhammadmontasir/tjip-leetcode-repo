// TC: O(N)
// MC: O(1)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> seenPrefixSumModK(k+1, 0);
        seenPrefixSumModK[0] = 1;
        int subArrCount = 0, preSum = 0;
        
        for (auto &num : nums)
        {
            preSum += num;
            while (preSum < 0) preSum += k;
            preSum %= k;
            subArrCount += seenPrefixSumModK[preSum];
            seenPrefixSumModK[preSum]++;
        }
        return subArrCount;
    }
};