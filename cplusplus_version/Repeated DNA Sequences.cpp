class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		int len = s.length();
		int times = len - 9;

		map<int,int>mp;
		vector<string> res;
		string str;
		for (int i = 0; i < times; i++) {
			str = s.substr(i, 10);
			int tmp = 0;
			for (int j = 0; j < 10; j++) {
				tmp = (tmp << 3 | str[j] & 7);
			}
			if (mp.find(tmp) != mp.end()) {
				if (mp[tmp] == 1) {
					res.push_back(str);
					mp[tmp] = 2;
				}
			}
			else {
				mp.insert(make_pair(tmp, 1));
			}
		}
		return res;


	}
};