// TC : O(N)
// MC : O(1)
class Solution {
public:
    int maxLenWithNUniqueChar(string s, int k, int nUnique) {
        int L = 0, R = 0, freqUnique = 0, freqAtleastK = 0, maxLen = 0;
        vector<int> freq(130, 0);
        
        while (R < s.size()) {
            freq[s[R]]++;
            freqUnique += freq[s[R]] == 1;
            freqAtleastK += freq[s[R]] == k;
            R++;
            while (freqUnique > nUnique) {
                freq[s[L]]--;
                freqUnique -= freq[s[L]] == 0;
                freqAtleastK -= freq[s[L]] == (k-1);
                L++;
            }
            if (freqUnique == freqAtleastK) {
                maxLen = max(maxLen, R - L);
            }
        }
        return maxLen;
    }
    // Suppose we have a function that can give us the max len of the string that has "N" unique characters repeating at least k times.
    int longestSubstring(string s, int k) {
        int lenMax = 0;
        for (int nUnique = 1; nUnique <= 26; nUnique++) {
            lenMax = max(lenMax, maxLenWithNUniqueChar(s, k, nUnique));
        }
        return lenMax;
    }
};