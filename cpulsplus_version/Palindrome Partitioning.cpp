class Solution {
public:
    vector<vector<string>> partition(string s) {

		vector<string> res;
		return findP(s, res);
	}

	vector<vector<string>> findP(string s, vector<string> prevs) {
		/*if (s.length() == 0) return res;
		if (s.length() == 1) patch(s);*/
		vector<vector<string>> res;
		for (unsigned int i = 1; i <= s.length(); i++) {
			vector<string> set;
			string str = s.substr(0, i);
			if (isPalindrome(str)) {
				for (string s : prevs) {
					set.push_back(s);
				}
				set.push_back(str);
				if (i == s.length()) {
					res.push_back(set);
				}
				else {
					vector<vector<string>> tmp = findP(s.substr(i), set);
					for (auto v : tmp) {
						res.push_back(v);
					}
					
				}
			}
		}
		return res;

	}
	

	bool isPalindrome(string s) {
		int begin = 0, end = s.length() - 1;
		while (begin < end) {
			if (s[begin] != s[end]) return false;
			begin++; end--;
		}
		return true;
	}
};