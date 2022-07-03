//TC: O(log N)
//MC: O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int dn = 5;
        while (n/dn > 0){
            res += n/dn;
            dn *= 5;
        }
        
        return res;
    }
};