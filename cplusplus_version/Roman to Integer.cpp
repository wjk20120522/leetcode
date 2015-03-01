/*
short code
 */
class Solution {
public:
	int romanToInt(string s) {
		int res = 0, len = s.length();
		map<char, int>charToInt = { { 'M', 1000 }, { 'D',500},
		{ 'C', 100 }, { 'L', 50 }, { 'X', 10 }, { 'V', 5 }, { 'I',1 }};
		
		for (int i = 0; i < len; i++) {
			if (i < len - 1 && charToInt[s[i]] < charToInt[s[i + 1]]) {
				res -= charToInt[s[i]];
			}
			else {
				res += charToInt[s[i]];
			}
		}
		return res;
	}
};


/*
scan from tail to front, fast
 */
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            switch (s[i]) {
            case 'I':
                res += (res >= 5 ? -1 : 1);
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                res += (res >= 50 ? -10 : 10);
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                res += (res >= 500 ? -100 : 100);
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
            }
        }
        return res;
    }
};