// TC: O(log(n))
// MC: O(N)
mt19937 rd(0);
class Solution
{
public:
    vector<int> sumWeight;
    int getRandomInRange(int L, int R)
    {
        return L + (rd() % (R - L + 1));
    }

    Solution(vector<int> &w)
    {
        sumWeight = w;
        for (int i = 1; i < sumWeight.size(); i++)
        {
            sumWeight[i] = sumWeight[i - 1] + w[i];
        }
    }

    int pickIndex()
    {
        int totalSum = sumWeight.back();
        int rnv = getRandomInRange(1, totalSum);
        return lower_bound(sumWeight.begin(), sumWeight.end(), rnv) - sumWeight.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */