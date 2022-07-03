// TC: O(N^2)
// MC: O(N)
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution
{
public:
    int calculatedScore(string &ref, string &cand)
    {
        int res = 0;
        for (int i = 0; i < ref.size(); i++)
        {
            res += (ref[i] == cand[i]);
        }
        return res;
    }

    void findSecretWord(vector<string> &wordlist, Master &master)
    {
        while (wordlist.size() > 1)
        {
            int rdx = rand() % wordlist.size();
            string queryString = wordlist[rdx];
            int score = master.guess(queryString);
            vector<string> newlist;

            for (auto &wd : wordlist)
            {
                if (calculatedScore(wd, queryString) == score)
                {
                    newlist.push_back(wd);
                }
                wordlist = newlist;
            }
        }
        master.guess(wordlist[0]);
    }
};