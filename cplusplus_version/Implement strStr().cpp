/*
clear brute force, since it is ranked easy, we may not use KMP or 
 */
class Solution {
public:
    int strStr(char *haystack, char *needle) {
		for (int i = 0;; i++) {
			for (int j = 0;; j++) {
				if (needle[j] == '\0') return i;   // find it
				if (haystack[i + j] == '\0') return -1;	  // to the end
				if (haystack[i + j] != needle[j]) break;  // next round
			}
		}
	}
};


/*
classic KMP
 */

class Solution {
public:
    int strStr(char *haystack, char *needle) {
		int i;
		int j = -1;
		const int n = strlen(haystack);
		const int m = strlen(needle);
		if (n == 0 && m == 0) return 0; /* "","" */
		if (m == 0) return 0; /* "a","" */
		int *next = (int*)malloc(sizeof(int)* m);
		compute_prefix(needle, next);
		for (i = 0; i < n; i++) {
			while (j > -1 && needle[j + 1] != haystack[i]) j = next[j];
			if (haystack[i] == needle[j + 1]) j++;
			if (j == m - 1) {
				free(next);
				return i - j;
			}
		}
		free(next);
		return -1;
	}

	void compute_prefix(const char *pattern, int next[]) {
		int i;
		int j = -1;
		const int m = strlen(pattern);
		next[0] = j;
		for (i = 1; i < m; i++) {
			while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];
			if (pattern[i] == pattern[j + 1]) j++;
			next[i] = j;
		}
	}
};