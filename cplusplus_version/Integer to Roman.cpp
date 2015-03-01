/*
replace every digit with corresponding Roman
 */
class Solution {
public:
    string intToRoman(int num) {
        string t[][10] = {
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},	//  digit
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},	// ten digit
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},	// hundred digit
			{"", "M", "MM", "MMM"},	// thounsand digit
		};
		return t[3][num / 1000] + t[2][num % 1000 / 100] + t[1][num % 100 / 10] + t[0][num % 10];	
    }
};


/*
easy to understand, fast but long code
 */
class Solution {
public:
	string intToRoman(int num) {
		string res;

		while (num) {
			if (num >= 1000) {
				res += "M"; num -= 1000;
			}
			else if (num >= 900) {
				res += "CM"; num -= 900;
			}
			else if (num >= 500) {
				res += "D"; num -= 500;
			}
			else if (num >= 400) {
				res += "CD"; num -= 400;
			}
			else if (num >= 100) {
				res += "C"; num -= 100;
			}
			else if (num >= 90) {
				res += "XC"; num -= 90;
			}
			else if (num >= 50) {
				res += "L"; num -= 50;
			}
			else if (num >= 40) {
				res += "XL"; num -= 40;
			}
			else if (num >= 10) {
				res += "X"; num -= 10;
			}
			else if (num >= 9) {
				res += "IX"; num -= 9;
			}
			else if (num >= 5) {
				res += "V"; num -= 5;
			}
			else if (num >= 4) {
				res += "IV"; num -= 4;
			}
			else if (num >= 1) {
				res += "I"; num--;
			}
		}
		return res;
	}
};