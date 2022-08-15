// TC: O(N)
// MC: O(N)
class Solution {
public:
    vector<int> cache;
    int ways(int pos, string &s) {
        if (pos >= s.size() || s[pos] == '0') return pos==s.size();
        if (cache[pos] != -1) return cache[pos];
        cache[pos] = ways(pos+1, s);
        if (stoi(s.substr(pos, 2)) < 27) cache[pos] += ways(pos + 2, s);
        return cache[pos];
    }
    int numDecodings(string s) {
        cache.clear();
        cache.resize(s.size()+1, -1);
        return ways(0, s);
    }
};