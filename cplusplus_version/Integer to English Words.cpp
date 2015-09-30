class Solution {
public:

    string ones[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                        "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    string twos[10] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string res;
        int billion = 1000000000, million = 1000000, thousand = 1000;
        bool hasNumBefore = false;
        if(num >= billion) {
            res += ones[num/billion] + " Billion";
            hasNumBefore = true;
            num -= num/billion*billion;
        }
        if(num >= million) {
            if(hasNumBefore) {
                res += " ";
            } else {
                hasNumBefore = true;
            }
            res += getInThousand(num/million) + " Million";
            num -= num/million*million;
        }
        if(num >= thousand) {
            if(hasNumBefore) {
                res += " ";
            } else {
                hasNumBefore = true;
            }
            res += getInThousand(num/thousand) + " Thousand";
            num -= num/thousand*thousand;
        }
        if(num != 0) {
            if(hasNumBefore) {
                res += " ";
            }
            res += getInThousand(num);
        }
        return res;
    }

private:
    string getInThousand(int hun) {
        string res;
        bool hasNumBefore= false;
        if(hun/100 >=1) {
            res += ones[hun/100] + " Hundred";
            hun -= hun/100*100;
            hasNumBefore = true;
        }
        if(hun >= 20) {
            if(hasNumBefore) res += " ";
            res += twos[hun/10];
            hun -= hun/10*10;
            if(hun != 0) {
                res += " " + ones[hun];
            }
        } else {
            if(hun != 0) {
                if(hasNumBefore) res += " ";
                res += ones[hun];
            }
        }
        return res;
    }
};