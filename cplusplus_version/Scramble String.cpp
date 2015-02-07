class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length()) return false;
		return scramString(s1.c_str(), 0, s1.length() - 1, s2.c_str(), 0, s2.length()-1);

	}

	bool scramString(const char*s1, int u, int v, const char* s2, int s, int t) {
		if (u == v && s1[u] == s2[s]) {
			return true;
		}

		int dic[256] = { 0 };
		for (int i = u; i <= v; i++) {
			dic[s1[i]] ++;
		}
		for (int i = s; i <= t; i++) {
			dic[s2[i]] --;
		}
		for (int i = 0; i < 256; i++) {
			if (dic[i] != 0) return false;
		}

		for (int i = u; i < v; i++) {
			if (scramString(s1, u, i, s2, s, i - u + s) && scramString(s1, i + 1, v, s2, -v + i + 1 + t, t))
				return true;
			if (scramString(s1, u, i, s2, u - i + t, t) && scramString(s1, i + 1, v, s2, s, v - i - 1 + s))
				return true;
		}

		return false;

	}


};