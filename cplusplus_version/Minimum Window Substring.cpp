class Solution {
public:
	string minWindow(string S, string T) {
		string res = "";
		if (S.length() <= 0 || T.size() <= 0) return res;

		// save the occurrence of each character
		unordered_map<char, int> dict;
		for (unsigned int i = 0; i < T.length(); i++) {
			dict[T[i]] ++;
		}

		unordered_map<char, int>mp;
		int left = 0;   // the most left index of all concatenate substring
		int count = 0;
		for (int j = 0; j <= (int)S.length() - 1; j++) {
			char cc = S[j];
			
			if (dict.count(cc)) {
				mp[cc] ++;
				if (mp[cc] <= dict[cc]) {
					count++;
				}
			}

			if (count == T.length()) {
				//abandon the redundant char
				while (dict.find(S[left]) == dict.end() || mp[S[left]] > dict[S[left]]){
					mp[S[left]]--;
					left++;
				}
				
				string tmp = S.substr(left, j - left + 1);
				if (res == "" || res.length() > tmp.length()) {
					res = tmp;
				}
			}

		}
	
		return res;
	}

	
};