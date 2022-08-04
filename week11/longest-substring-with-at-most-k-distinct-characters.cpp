// TC : O(26*N)
// MC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthAtMostKDistinct(string s, int k){
        int L = 0, R = 0, maxLen = 0, distinctChar = 0;
        vector<int> freq(256, 0);

        while(R < s.size()) {
            freq [s[R]]++;
            distinctChar += (freq[s[R]] == 1);
            R++;
            while (distinctChar > k) {
                freq[s[L]]--;
                distinctChar -= (freq[s[L]]==0);
                L++;
            }
            maxLen = max(maxLen, R - L);
        }
        return maxLen;
    }
};

int main()
{
    Solution solution;
    cout<<solution.lengthAtMostKDistinct("eceba", 2)<<endl;
    return 0;
}
