/**
 * more neat code
 * 
 */
class Solution {
public:
	bool isPalindrome(string s) {
		int begin = 0, end = s.length() - 1;
		while (begin < end) {
			while (begin < end && !isalnum(s[begin])) begin++;
			while (begin < end && !isalnum(s[end])) end--;
			if (tolower(s[begin]) != tolower(s[end])) return false;
			begin++; end--;
		}
		return true;
	}
};