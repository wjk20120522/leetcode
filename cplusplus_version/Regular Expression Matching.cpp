class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!*p) return !*s;       // p is empty

        // p is not empty
        if (*(p + 1) == '*') {
        	return isMatch(s, p + 2) || *s && (*s == *p || *p == '.') && isMatch(s + 1, p);
        }
        else {
        	if (!*s) return false;
        	return (*s == *p || *p == '.') ?  isMatch(s + 1, p + 1) : false ;

        }
    }
};