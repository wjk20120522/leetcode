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