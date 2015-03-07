class Solution {
public:
	vector<string> letterCombinations(string digits) {
		string alph [][4] = { {}, {}, { "a", "b", "c" }, { "d", "e", "f" }, { "g", "h", "i" },
		{ "j", "k", "l" }, { "m", "n", "o" }, { "p", "q", "r", "s" }, { "t", "u", "v" }, {"w","x","y","z"} };
		vector<string>res,tmp;
		for (int i = 0; i < digits.length(); i++) {
			int num = digits[i] - '0';
			
			if (i == 0) { // first letter
				tmp.push_back(alph[num][0]);
				tmp.push_back(alph[num][1]);
				tmp.push_back(alph[num][2]);
			}
			else {
				for (string str : res) {
					tmp.push_back(str + alph[num][0]);
					tmp.push_back(str + alph[num][1]);
					tmp.push_back(str + alph[num][2]);
				}
			}
			if (num == 7 || num == 9) {
				if (i == 0) tmp.push_back(alph[num][3]);
				else {
					for (string str : res) {
						tmp.push_back(str + alph[num][3]);
					}
				}
			}
			res = tmp;
			tmp.clear();
		}
		return res;
	}
};