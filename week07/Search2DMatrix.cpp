class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int L = 0, R = matrix[0].size() * matrix.size() - 1;

        while (L <= R)
        {
            int MID = L + (R - L) / 2;
            int row = MID / matrix[0].size();
            int col = MID % matrix[0].size();
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] < target)
                L = MID + 1;
            else
                R = MID - 1;
        }
        return false;
    }
};