class Solution {
public:
    int sqrt(int x) {
         int64_t begin = 0, end = 50000;
		 int64_t mid = (begin + end) / 2;
		 while (true) {
			 int64_t sqr = mid*mid;
			 if (sqr < x) {
				 if ((mid + 1)*(mid + 1) > x) return mid;
				 begin = mid + 1;
			 }
			 else if (sqr > x) {
				 end = mid - 1;
			 }
			 else {
				 return mid;
			 }
			 mid = (begin + end) / 2;
		 }
    }
};