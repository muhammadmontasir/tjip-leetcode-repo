class Solution
{
public:
    bool isPossible(vector<int> &dist, double hour, int speed)
    {
        double time = 0;
        for (int i = 0; i < dist.size() - 1; i++)
        {
            time += ceil((double)dist[i] / speed);
        }
        time += (double)dist.back() / speed;

        return time <= hour;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int L = 1, R = 1e7;
        if (hour <= (double)dist.size() - 1)
            return -1;

        while (L < R)
        {
            int MID = L + (R - L) / 2;
            if (isPossible(dist, hour, MID))
                R = MID;
            else
                L = MID + 1;
        }
        return R;
    }
};