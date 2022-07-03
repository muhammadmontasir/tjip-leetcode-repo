class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> stk;
        string result;
        stk.push(num[0]);
        for (int i = 1; i < num.size(); i++)
        {
            while (k > 0 and !stk.empty() and num[i] < stk.top())
            {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while (k > 0 and !stk.empty())
        {
            stk.pop();
            k--;
        }

        while (!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        while (!result.empty() and result.back() == '0')
            result.pop_back();

        if (result.empty())
            return "0";
        reverse(result.begin(), result.end());
        return result;
    }
};