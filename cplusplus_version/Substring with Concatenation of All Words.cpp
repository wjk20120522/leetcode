
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> res;
		if (S.length() <= 0 || L.size() <= 0) return res;

		// save the occurrence of each word
		unordered_map<string, int> dict;
		for (int i = 0; i < L.size(); i++) {
			dict[L[i]] ++;
		}

		int wl = L[0].size();
		for (int i = 0; i < wl; i++) {
			unordered_map<string, int>mp;
			int left = i;   // the most left index of all concatenate substring
			int count = 0;
			for (int j = i; j <= (int)S.length() - wl; j+=wl) {
				string str = S.substr(j, wl);
				if (dict.count(str)) {
					mp[str] ++;
					if (mp[str] > dict[str]) {    //occurrence times bigger than expected
						while (mp[str] > dict[str]) {
							string str1 = S.substr(left, wl);
							mp[str1] --;
							if (mp[str1] < dict[str1]) count--;  //until meet str
							left += wl;
						}
					}
					else {
						count++;
					}
					if (count == L.size()) {
						res.push_back(left);
						// move left window
						mp[S.substr(left, wl)] --;
						count--;
						left += wl;

					}
				}
				else {
					mp.clear();
					count = 0;
					left = j + wl;
				}

			}
		}
		return res;

	}
};