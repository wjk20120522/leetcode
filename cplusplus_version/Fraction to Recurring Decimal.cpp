class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
		if (numerator == 0) return "0";
		//note the negative
		if (numerator < 0 ^ denominator < 0) res += "-";
		
		// note here may occure a big mistake , just use int64_t n = (abs)numerator
		int64_t n = numerator, d = denominator;
		n = abs(n);
		d = abs(d);

		// the interger part
		res += to_string(n / d);
		// no fraction
		if (n % d == 0) return res;
		res += ".";
		int64_t r;

		//calculate fraction
		unordered_map<int, int> map;
		for (r = n%d; r; r = r%d) {
			if (map.find(r) != map.end()) { // recurring occures
				res.insert(map[r], 1, '(');
				res += ')';
				return res;
			}
			map[r] = res.size();

			r *= 10;
			res += to_string(r / d);
			
		}
		return res;
    }
};