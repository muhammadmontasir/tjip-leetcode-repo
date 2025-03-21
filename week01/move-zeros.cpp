class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cntZeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) cntZeros++;
        }
        
        vector <int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) ans.push_back(nums[i]);
        }
        
        for (int i = 0; i < cntZeros; i++) ans.push_back(0);
        
        for (int i = 0; i < nums.size(); i++) nums[i] = ans[i];
    }
};