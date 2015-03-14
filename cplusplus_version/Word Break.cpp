class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.length() == 0) return true;
		 vector<bool>dp(s.size() + 1, false);
		 dp[0] = true;
		 for (unsigned int i = 1; i <= s.length(); i++) {
			 for ( int j = i - 1; j >= 0; j--) {
				 if (dp[j]) {
					 string str = s.substr(j, i - j);
					 if (dict.find(str) != dict.end()) {
						 dp[i] = true; break;
					 }
				 }
			 }
		 }
		 return dp[s.length()];
    }
};


/*
simlilar method
 */
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> visit(s.length(), false);
		visit[0] = true;
		for (int i = 0; i < s.length(); i++) {
			// if j change from 0 to i, it costs more time, maybe test specific
			for (int j = i; j >=0; j--) {
				if (visit[j] && dict.find(s.substr(j, i - j + 1)) != dict.end()) {
					visit[i+1] = true;
					break;
				}
			}
		}
		return visit[s.length()];
	}
};