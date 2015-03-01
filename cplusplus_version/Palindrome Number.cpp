/*
use two int
 */
class Solution {
public:
    bool isPalindrome(int x) {
    	int res = 0;
    	int temp = x;
    	if(temp < 0) {
    		return false;
    	}
    	while(temp) {
    		res = res*10 + temp%10;
    		temp /= 10;
    	}
    	if(x == res) {
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


/*
use another int to save the reverse of x
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x!=0 && x%10==0)) return false;
        int rev = 0;
        while (x>rev){
            rev = rev*10 + x%10;
            x = x/10;
        }
        return (x==rev || x==rev/10);
    }
};


/*
no extra space used, but may hard to write code correctly
 */
#define order(x) ((int)pow(10, (int)log10(x)))

bool isPalindrome(int x) {
    // non palindrome number for negative numbers
    if (x < 0)
        return false;

    while (x) {
        // non palindrome if the most significant digit
        // doesn't match the least one
        if (x % 10 != x / order(x))
            return false;

        // remove both the most and the least digit
        // if the second most significant digit is NOT 0,
        if (order(x) / 10 == order(x - x % 10 * order(x)))
            x = (x - x % 10 * order(x)) / 10;

        // it's 0, then make sure the second least is also 0
        // non palindrome if otherwise
        else if (x / 10 % 10 != 0)
            return false;

        // now the second most and the second least are both 0,
        // remove the most and the least, and change the two 0's to 1's
        else
            x = (x - x % 10 * order(x) + order(x) / 10) / 10 + 1;
    }

    return true;
}