class Solution {
public:
	bool isValid(string s) {
		stack<char>sta;
		for (unsigned int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				sta.push(s[i]);
			}
			else{				// need to compare to the prev
				if (sta.empty()) return false;
				if (sta.top() + 1 == s[i] || sta.top() + 2 == s[i]) {   // match
					sta.pop();
				}
				else {
					return false;
				}
			}
		}
		return sta.empty();
	}
};