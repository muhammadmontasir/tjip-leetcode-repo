// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// TC: O(N)
// MC: O(1)
class Solution
{
public:
    int firstBadVersion(int n)
    {
        int L = 0, R = n;
        while (L < R)
        {
            int M = L + (R - L) / 2;
            if (isBadVersion(M))
                R = M;
            else
                L = M + 1;
        }
        return L;
    }
};