class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        double xN = x, prv = 0;
        while (fabs(xN - prv) >= 1e-6)
        {
            prv = xN;
            xN = (xN * xN + x) / (2 * xN);
        }
        return xN;
    }
};