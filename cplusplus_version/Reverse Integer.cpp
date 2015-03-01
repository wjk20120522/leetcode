/*
use a long long int or to save -x
 */
class Solution {
public:
	int reverse(int x) {
		long long int rev=0;
		bool neg = x < 0 ? true : false;
		x = x < 0 ? -x : x;
		while (x) {
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		if (neg) rev = -rev;
		if (rev < INT_MIN || rev > INT_MAX)
			return 0;
		return rev;
	}
};


/*
similar like above but shorter...
 */
class Solution {
public:
	int reverse(int x) {
		long long res = 0;
		while (x) {
			res = res * 10 + x % 10;   // based on fact taht neg %10 return neg
			x /= 10;
		}
		return (res<INT_MIN || res>INT_MAX) ? 0 : res;
	}
};


/*
another method: use only int
 */
class Solution {
public:
    int reverse(int x) {
        int neg = (x < 0) ? -1 : 1;
		int result = 0;
		int temp = x * neg;	// I think this may cause some problem, x = -2147483647-1
		while (temp > 0)
		{
			if (result > INT_MAX/10)
				return 0;
			result = result * 10 + temp % 10;
			temp /= 10;
		}

		return  neg * result;
    }
};


/*
similar like above
 */
int reverse(int x) {
    static const int overflow = INT_MAX / 10;
    const char mod = x < 0 ? -10 : 10;
    int r = 0;

    while (x) {
        if (r > overflow || r < -overflow)  // I think this may cause some problem
            return 0;
        r = (x % mod) + (r * 10);
        x /= 10;
    }

    return r;
}
