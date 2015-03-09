class Solution {
public:
    double pow(double x, int n) {
        double res = 1.0;
        bool neg = false;
        if(n <0) 
        {
            neg = true; n = -n;
        }
		while (n >= 1)
		{
			if (n % 2 == 1)
			{
				res *= x;
			}
			x *= x;
			n /= 2;
		}
		if(neg) return 1.0/res;
		return res;
    }
};


/*
recursive method
 */
class Solution {
public:
    double pow(double x, int n) {
		if (n == 0) return 1;
		if (n == 1) return x;

		bool neg = (n<0) ? true : false;
		n = abs(n);
		double res = pow(x, n / 2);
		if (n % 2) {
			return neg ? 1.0/(res*res*x) : res*res*x;
		}
		else {
			return neg ? 1.0/(res*res) : res*res;
		}
    }
};