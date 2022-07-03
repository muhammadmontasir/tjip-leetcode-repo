class Solution
{
public:
    double findMedianSortedArrays(vector<int> &num1, vector<int> &num2)
    {
        for (int i = 0; i < num2.size(); i++)
            num1.push_back(num2[i]);

        sort(num1.begin(), num1.end());
        int len = num1.size();

        if (len % 2 != 0)
            return num1[len / 2];
        else
            return (num1[len / 2] + num1[len / 2 - 1]) / 2.00000;
    }
};