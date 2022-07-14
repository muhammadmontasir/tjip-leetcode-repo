class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // very imp to remove duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                // very imp to remove duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // overflowing int,that's why *1L(typecasting to long)
                long long tar = target - nums[i] * 1L - nums[j];

                int start = j + 1, end = n - 1;
                while (start < end)
                {
                    if (nums[start] + nums[end] < tar)
                        start++;
                    else if (nums[start] + nums[end] > tar)
                        end--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});

                        int val = nums[start];
                        while (start < end && nums[start] == val)
                            start++;

                        val = nums[end];
                        while (start < end && nums[end] == val)
                            end--;
                    }
                }
            }
        }
        return ans;
    }
};