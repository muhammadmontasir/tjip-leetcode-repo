// TC: O(12*N)
// MC: O(N)
class Solution {
public:
    vector<int> cache;
    int countMinCoins(int amount, vector<int> &coins) {
        if (amount == 0) return 0;
        if (cache[amount] != -1) return cache[amount];
        int minCoins = INT_MAX / 2;
        for (auto &coin : coins) {
            if (amount >= coin) {
                minCoins = min(minCoins, 1 + countMinCoins(amount - coin, coins));
            }
        }
        return cache[amount] = minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        cache.clear();
        cache.resize(amount+1, -1);
        int minCoins = countMinCoins(amount, coins);
        return minCoins > amount ? -1 : minCoins;
    }
};