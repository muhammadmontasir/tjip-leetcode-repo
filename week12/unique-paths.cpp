// TC: O(NM)
// MC: O(NM)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int cache[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++){
                if (i == 0 || j == 0) cache[i][j] = 1;
                else cache[i][j] = cache[i-1][j] + cache[i][j-1];
            }
        return cache[m-1][n-1];
    }
};