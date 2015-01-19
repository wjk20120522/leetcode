class Solution {
public:
    int numDecodings(string s) {
		// int len = s.length();
		 if (s.length() == 0) return 0;
		 vector<int>num(s.length()+1, -1);
		 //num[0] = 1;
		 return DP(s.length(), s, num);

	 }

	 int DP(int len, string &s, vector<int>&num) {
		 if (len == 0) return 1;
		 if (len == 1) {
			 if (s[0] == '0') return 0;
			 return 1;
		 }
		 if (num[len] == -1) {
			 //must be split
			 if ( (s[len - 2] == '0' && s[len-1] !='0') || ((s[len - 2] - '0') * 10 + s[len - 1] - '0') > 26 && s[len-1] !='0') num[len] = DP(len - 1, s, num);
			 //must be together
			 else if (s[len - 1] == '0' && (s[len - 2] == '1' || s[len - 2] == '2')) num[len] = DP(len - 2, s, num);
			 // can 1 or two
			 else if (s[len - 1] != '0' && s[len - 2] != '0' && (s[len - 2] - '0') * 10 + s[len - 1] - '0' <= 26) num[len] = DP(len - 1, s, num) + DP(len - 2, s, num);
			 // can match 
			 else num[len] = 0;
		 }
		return num[len];
	 }

};