class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int>mp;
		vector<string> res;
		int val, times;
		for (int i = 0; i <= (int)s.length() - 10; i++) {
			val = 0;
			for (int j = i; j < i + 10; j++) {
				val |= (s[j] & 7) << (j - i)*3;
			}
			if (mp.find(val) != mp.end()) {
				if (mp[val] == 1)
					res.push_back(s.substr(i, 10));
				mp[val]++;
			}
			else {
				mp[val] = 1;
			}
		}
		return res;
    }
};