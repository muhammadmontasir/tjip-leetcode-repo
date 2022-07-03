//TC: O(N)
//MC: O(N)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string res;
        if (numerator > 0 != denominator > 0) res += "-";
        
        long absNumerator = labs(numerator);
        long absDenominator = labs(denominator);
        res += to_string(absNumerator / absDenominator);
        long remainder = absNumerator % absDenominator;
        
        if (!remainder) return res;
        res += ".";
        
        unordered_map<long, int> remainderMap;
        while(remainder) 
        {
            if (remainderMap.find(remainder) != remainderMap.end())
            {
                res.insert(remainderMap[remainder], "(");
                res += ")";
                break;
            }
            remainderMap[remainder] = res.size();
            remainder *= 10;
            res += to_string(remainder/absDenominator);
            remainder %= absDenominator;
        }
        return res;
    }
};