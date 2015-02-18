class Solution {
public:
	string countAndSay(int n) {
		string res = "1", tmp;
		for (int i = 1; i < n; i++) {
			tmp = "";
			int len = res.length();
			for (int j = 0; j < len; j++) {
				int begin = j;
				while (j < len - 1 && res[j] == res[j + 1]) j++;
				tmp += to_string(j - begin+1) + res[begin];
			}
			res = tmp;
		}
		return res;
	}
};