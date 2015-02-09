/**
 * easy to understand
 */
class Solution {
public:
	int longestValidParentheses(string s) {
		//int v[]
		int len = s.length();
		if (len == 0) return 0;
		vector<int> v(len);
		int max = 0;
		/**
		 * s[i] = (  => 0
		 * s[i] = )   s[i-1] = (  => 2 + v[i-2]
		 * 			  s[i-1] = )  =>  2 + v[i-1]  + v[i-2-v[i-1]]
		 */
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') { v[i] = 0; }
			else {     // ')'
				if (i>0 && s[i - 1] == '(') {
					v[i] = 2 + (i >= 2 ? v[i - 2] : 0 );
				}
				else if (i > 0 && s[i - 1] == ')') {
					if (  i-1-v[i-1] >=0 && s[i - 1 - v[i - 1]] == '(') {
						v[i] = v[i - 1] + 2 + ( (i - 1 - v[i - 1] > 0) ? v[i - 2 - v[i - 1]] : 0 );
					}
				}
				else {
					v[i] = 0;
				}
				max = max > v[i] ? max : v[i];
			}
		}
		return max;

	}
};

/**
 * more clean and conscise code
 */
/*
class Solution {
public:
	int longestValidParentheses(string s) {
	    int len = s.length();
		vector<int> v(len);
		int max = 0;
		for (int i = 1; i < len; i++) {
			if (s[i] == ')' &&  i - 1 - v[i - 1] >= 0 && s[i - 1 - v[i - 1]] == '(') {    // if the match parenthese
				v[i] = v[i - 1] + 2 + ((i - 1 - v[i - 1] > 0) ? v[i - 2 - v[i - 1]] : 0);
			}
			max = max > v[i] ? max : v[i];
		}
		return max;
	}
};
*/