/*
from back to front
 */

class Solution {
public:
    int numDecodings(string s) {
		if (s.length() == 0) return 0;
		vector<int>num(s.length()+1, -1);
		return DP(s.length(), s, num);
	}

	int DP(int len, string &s, vector<int>&num) {
		if (len == 0) return 1;		// no character
		if (len == 1) {				// only one character
			return s[0] == '0' ? 0 : 1;
		}
		if (num[len] == -1) {
			//must be split
			if ( (s[len - 2] == '0' && s[len-1] !='0') || ((s[len - 2] - '0') * 10 + s[len - 1] - '0') > 26 && s[len-1] !='0') 
				num[len] = DP(len - 1, s, num);
			//must be together
			else if (s[len - 1] == '0' && (s[len - 2] == '1' || s[len - 2] == '2')) 
				num[len] = DP(len - 2, s, num);
			// can 1 or two
			else if (s[len - 1] != '0' && s[len - 2] != '0' && (s[len - 2] - '0') * 10 + s[len - 1] - '0' <= 26) 
				num[len] = DP(len - 1, s, num) + DP(len - 2, s, num);
			// can match 
			else num[len] = 0;
		}
		return num[len];
	}
};


/*
from front to back
 */
class Solution {
public:
    int numDecodings(string s) {
		int len = s.length();
		if (len == 0) return 0;
		vector<int>num(len, -1);
		return numDecodings(s, 0, num, len);
    }

	int numDecodings(string s, int idx, vector<int>&num, int len) {
		if (idx == len) return 1;
		if (num[idx] != -1) return num[idx];

		if (idx == len - 1) {  // the last character
			num[idx] = (s[idx] == '0' ? 0 : 1);
		}
		else if (s[idx] == '0') {	//0
			num[idx] = 0;
		}
		else if (s[idx] >= '3' || (s[idx] == '2' && s[idx+1] >'6')) {	//3-9
			num[idx] = numDecodings(s, idx + 1, num, len);
		}
		else {
			num[idx] = numDecodings(s, idx + 2, num, len) + numDecodings(s, idx + 1, num, len);
		}
		return num[idx];
	}
};