class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0, res =0; 

		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] == ' ') {
				if (len != 0)
					res = len;
				len = 0;
			}
			else len++;
		}
		if (len) return len;
		return res;
    }
};