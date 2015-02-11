class Solution {
public:
	int numDistinct(string S, string T) {
		int len1 = S.length();
		int len2 = T.length();
		if (len2 > len1) return 0;    

		vector< vector<int> > mem(len1, vector<int>(len2,-1));

		return distinct(S, len1 - 1, T, len2 - 1, mem);

	}

	int distinct(string& S, int lens, string& T, int lent, vector< vector<int> >&mem) {
		if (lent == -1) return 1;
		if (lens == -1) return 0;

		if (S[lens] == T[lent]) {
			if (mem[lens][lent] == -1) {
				mem[lens][lent] = distinct(S, lens - 1, T, lent - 1, mem) + distinct(S, lens - 1, T, lent, mem);
			}
		}
		else {
			mem[lens][lent] = distinct(S, lens - 1, T, lent, mem);
		}
		return mem[lens][lent];


	}
};