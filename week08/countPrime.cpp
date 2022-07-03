// TC: O(log(log N))
// MC: O(N)
class Solution
{
public:
    vector<int> primes;
    int sieve(int n)
    {
        bool isPrime[n];

        for (int i = 2; i < n; i++)
            isPrime[i] = true;

        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i] == true)
            {
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;
            }
        }

        primes.push_back(2);

        for (int i = 3; i < n; i += 2)
            if (isPrime[i])
                primes.push_back(i);

        return primes.size();
    }

    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        return sieve(n);
    }
};
