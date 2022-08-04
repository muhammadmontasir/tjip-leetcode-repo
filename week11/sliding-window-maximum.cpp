// TC: O(N^2)
// MC: O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> decreasingSubseqK;
        vector <int> maxOfWindow;
        for (int i = 0; i < nums.size(); i++) {
            while (!decreasingSubseqK.empty() && i - k >= decreasingSubseqK.front())
                decreasingSubseqK.pop_front();
            while (!decreasingSubseqK.empty() && nums[i] > nums[decreasingSubseqK.back()])
                decreasingSubseqK.pop_back();
            decreasingSubseqK.push_back(i);
            if (i >= k-1)
                maxOfWindow.push_back(nums[decreasingSubseqK.front()]);
        }
        return maxOfWindow;
    }
};