class Solution {
public:
	void reverseWords(string &s) {
		string tmp;
		int end;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				end = i;
				while (end < s.length() && s[end] != ' ') end++;
				if (tmp == "") {
					tmp = s.substr(i, end - i);
				}
				else {
					tmp = s.substr(i, end - i) + " " + tmp;
				}
				i = end;
			}
		}
		s = tmp;
	}
};