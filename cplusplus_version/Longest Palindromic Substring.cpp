class Solution {
public:
	string longestPalindrome(string s) {
		first = 0, second = 0;
		for (int i = 1; i < s.length(); i++) {
			// for odd
			longestPalindrome(i ,i, s);
			// for even
			if (s[i] == s[i - 1]) {
				longestPalindrome(i - 1, i, s);
			}
		}
		return s.substr(first, second - first + 1);
	}

	void longestPalindrome(int head, int tail, string& s) {
		while (head >= 0 && tail < s.length()) {
			if (s[head] == s[tail]) {
				head--; tail++;
			}
			else break;
		}
		head++; tail--;
		if (tail - head > second - first) {
			second = tail;
			first = head;
		}
	}
	
private:
	int first, second;
};