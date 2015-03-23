class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
		if (numerator == 0) return "0";
		if (numerator > 0 ^ denominator > 0) res += "-";
		long long n = numerator, d = denominator;
		n = abs(n), d = abs(d);
		res += to_string(n/d);
		if (n%d==0) return res;
		res += ".";
		unordered_map<int, int> mp;

		for (long long int r = n%d; r; r = r%d) {
			if (mp.find(r) != mp.end()) {  // occures again
				res.insert(mp[r], 1, '(');
				res += ")"; return res;
			}
			mp[r] = res.size();

			r *= 10;
			res += to_string(r / d);
		}
		return res;
    }
};