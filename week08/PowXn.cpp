class Solution
{
public:
    double modExpo(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        if (n % 2 == 0)
        {
            auto temp = modExpo(x, n / 2);
            return temp * temp;
        }
        return x * modExpo(x, n - 1);
    }

    double myPow(double x, int n)
    {
        bool invFlag = n < 0;
        if (n == 0)
            return 1.0;
        long long degree = (invFlag) ? 1LL * (-1) * n : n;
        double res = modExpo(x, degree);
        res = (invFlag) ? 1.0 / res : res;
        return res;
    }
};