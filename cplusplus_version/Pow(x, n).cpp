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