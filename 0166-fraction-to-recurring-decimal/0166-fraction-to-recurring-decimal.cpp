class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = numerator;
        long denominatorLong = denominator;
        int modulus = numeratorLong % denominatorLong;
        if (!modulus){
            return to_string(numeratorLong/denominatorLong);
        }
        string res;
        if (numerator<0 ^ denominator<0){
            res += '-';
        }
        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        long integerPart = numeratorLong / denominatorLong;
        res += to_string(integerPart);
        res += '.';
        string fractionPart;
        unordered_map<long, int> remainderIndexMap;
        int index = 0;
        long remainder = numeratorLong % denominatorLong;
        while (remainder != 0 && !remainderIndexMap.count(remainder)) {
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fractionPart += to_string(remainder / denominatorLong);
            remainder %= denominatorLong;
            index++;
        }
        if (remainder != 0){
            int insertIndex = remainderIndexMap[remainder];
            fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex) + ')';
        }
        res += fractionPart;
        return res;
    }
};