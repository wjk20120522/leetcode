class Solution {
public:
	int minCut(string s) {

		int n = s.length();
		if (n <= 1) return 0;

		vector< vector<bool> >ispalindr(n + 1, vector<bool>(n + 1, false));
		vector<int>dp(n + 1);

		for (int i = 0; i < n; i++) dp[i] = i ;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j <=i; j++) {

				if (s[j] == s[i] && ( i-j <= 2 || ispalindr[j+1][i-1]  )) {
					
					ispalindr[j][i] = true;
					if (j == 0) {
						dp[i] = 0;
						break;
					}
					else {
						dp[i] = min(dp[i], dp[j - 1] + 1);
					}
					
				}
			}
		}
		return dp[n-1];
	}

	
};