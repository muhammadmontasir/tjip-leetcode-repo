// TC: O(N*N^0.5)
// MC: O(N)

class Solution {
public:
    
    vector<int> cache;
    int perfectSquareLeast(int n) {
        int minCount = INT_MAX / 2;
        if (n < 2) return n;
        if (cache[n] != -1) return cache[n];
        for (int i = 1; i*i <=n; i++){
            minCount = min(minCount, 1 + perfectSquareLeast(n - i*i));
        }
        return cache[n] = minCount;
    }
    int numSquares(int n) {
        cache.clear();
        cache.resize(n+1, -1);
        return perfectSquareLeast(n);
    }
};
// iterative
class Solution {
public:
    int numSquares(int n) {
        vector<int> cache(n+1, INT_MAX / 2);
        cache[0] = 0;
        cache[1] = 1;
        for (int currNumber = 1; currNumber <= n; currNumber++) {
            for (int sq = 1; sq*sq <= currNumber; sq++) {
                cache[currNumber] = min(cache[currNumber], 1 + cache[currNumber - sq* sq]);
            }
        }
        return cache[n];
    }
};