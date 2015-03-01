class Solution {
public:
	int atoi(string str) {
		bool neg = false;
		int i, j, len = str.length();
		long long int res = 0;
		// skip front white space
		for (i = 0; i < len; i++) {
			if (str[i] != ' ') break;
		}
		// optional sign
		if (i < len && (str[i] == '-' || str[i] == '+')) {
			neg = (str[i] == '-');
			i++;
		}

		for (; i < len; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				res = res * 10 + str[i] - '0';
				// overflow or underflow, then return
				if ((neg && -res < INT_MIN) || (!neg && res > INT_MAX)) {
					return neg ? INT_MIN : INT_MAX;
				}
			}
			else {
				break;
			}
		}

		return neg ? -res : res;
	}
};