class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n <= 0) return 0;
		 int maxNow = A[0]; 
		 int maxEndHere = A[0], maxEndHerePrev = A[0];
		 int minEndHere = A[0], minEndHerePrev = A[0];
		 // note : negative * negative can be largest
		 // two prev save previous max and min
		 for (int i = 1; i < n; i++) {
			
			 maxEndHere = maxEndHere * A[i] > A[i] ? maxEndHere * A[i] : A[i];
			 maxEndHere = minEndHerePrev * A[i] > maxEndHere ? minEndHerePrev * A[i] : maxEndHere;

			 minEndHere = minEndHere * A[i] < A[i] ? minEndHere * A[i] : A[i];
			 minEndHere = maxEndHerePrev *A[i] < minEndHere ? maxEndHerePrev *A[i] : minEndHere;

			
			 maxNow = maxNow > maxEndHere ? maxNow : maxEndHere;

			 minEndHerePrev = minEndHere;    maxEndHerePrev = maxEndHere;
		 }
		 return maxNow;
    }
};


/*
similar like above
 */
class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) return 0;
		int res = A[0];

		int maxNow = A[0];
		int minNow = A[0], minPre;
		for (int i = 1; i < n; i++) {
			minPre = minNow;
			minNow = min(A[i], minPre*A[i]);
			minNow = min(minNow, A[i] * maxNow);

			maxNow = max(A[i], maxNow*A[i]);
			maxNow = max(maxNow, minPre*A[i]);
			res = max(res, maxNow);
		}
		return res;
    }
};