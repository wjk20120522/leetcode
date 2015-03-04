class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		if (s.length() == 0) {
			vector<string>tmp;
			res.push_back(tmp);
			return res;
		}
		for (int i = 1; i <= s.length(); i++) {
			string str = s.substr(0, i);
			if (isPalindrome(str)) {
				// find back string result first
				vector<vector<string>> tmpres = partition(s.substr(i));
				for (auto tmp : tmpres) {
					tmp.insert(tmp.begin(), str);
					res.push_back(tmp);
				}
			}
		}
		return res;
	}

	bool isPalindrome(string str) {
		for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
			if (str[i] != str[j]) return false;
		}
		return true;
	}
};