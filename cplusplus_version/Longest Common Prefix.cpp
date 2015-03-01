class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res,tmp;
		int len = 0;
		for (int i = 0; i < strs.size(); i++) {
			if (strs[i].size() > len) len = strs[i].size();
		}
		for (int i = 0; i < len; i++) {
			tmp = strs[0].substr(0, i + 1);
			for (int j = 1; j < strs.size(); j++) {
				if (strs[j].find(tmp) != 0) {  // if not the index 0 then fail
					return res;
				}
			}
			res = tmp;		// update the longer substr
		}
		return res;
    }
};