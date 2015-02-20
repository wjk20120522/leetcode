/*
use two int
 */
class Solution {
public:
    bool isPalindrome(int x) {
    	int res = 0;
    	int temp = x;
    	if(x < 0) {
    		return false;
    	}
    	while(x) {
    		res = res*10 + x%10;
    		x /= 10;
    	}
    	if(temp == res) {
    		return true;
    	}
    	return false;
    }
};

/*
another similar method
 */
class Solution {
public:
    bool isPalindrome(int x) {
        //special case
        if (x == INT_MIN || x<0) return false;   // no corresponding positive number
        
        int digits = log10(x)+1;
        for (int i = 1; i <= digits / 2; i++) {
            int right = ((x % (int)pow(10, i)) / pow(10, i - 1));
            int left = (int)(x / pow(10, digits - i)) % 10;
            if (left != right)
                return false;
        }
        return true;
    }
};