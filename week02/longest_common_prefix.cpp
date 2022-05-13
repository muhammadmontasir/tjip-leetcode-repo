// TC: O(N)
// MC: O(1)
class Solution
{
public:
    string findLCP(string &a, string &b)
    {
        int index = 0;
        while (a[index] && b[index] && a[index] == b[index])
            index++;

        return a.substr(0, index);
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        string lcp = strs[0];
        for (auto str : strs)
        {
            lcp = findLCP(lcp, str);
        }
        return lcp;
    }
};