/*
use sort, c++ STL
 */
class Solution {
public:
	string largestNumber(vector<int> &num) {
		vector<string> res;
		for (auto i : num) {
			res.push_back(to_string(i));
		}

		sort(res.begin(), res.end(), [](string& s1, string& s2) {return s1 + s2 > s2 + s1; });

		string out;
		for (auto str : res) {
			out += str;
		}
		if (out[0] == '0' || out == "") return "0";
		return out;
	}
};


/*
use qsort, c
 */
int cmp(const void *a, const void *b) {
	string str1 = to_string(*(int *)a);
	string str2 = to_string(*(int *)b);

	return str1 + str2 < str2 + str1;
}

class Solution {
public:
	string largestNumber(vector<int> &num) {
		string res;
		qsort(&num[0], num.size(), sizeof(int), cmp);
		int i = 0;
		while (i < num.size() - 1 && num[i] == 0) i++;
		for (; i < num.size(); i++) {
			res += to_string(num[i]);
		}
		return res;
	}
};