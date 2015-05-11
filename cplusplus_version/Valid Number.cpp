class Solution {
public:
    bool isNumber(string str) {
        if(str.size() == 0) return false;
        char *s = &str[0];
        while (*s == ' ') ++s;
        if (*s == '+' || *s == '-') ++s;
        bool exp = false, space = false, point = false;
        bool number = false;
        while (*s != '\0') {
            if (isdigit(*s)) {
                if (space) return false;
                else number = true;
            } else if (*s == '.') {
                if (!point && !space && !exp) {
                    point = true;
                } else {
                    return false;
                }
            } else if (*s == 'e' || *s == 'E') {
                if (!exp && number && !space) {
                    exp = true;
                    number = false;
                    while (*(s+1) == '+' || *(s+1) == '-') ++s;
                } else {
                    return false;
                }
            } else if (*s == ' ') {
                if (!space) {
                    space = true;
                }
            } else {
                return false;
            }
            ++s;
        }
        return number;
    }
};