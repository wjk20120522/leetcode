class Solution {
public:
    int maxSubArray(int A[], int n) {
        //  if (n < 1) return 0;
        //linear time
		int maxEnd = 0, maxNow = A[0];
		for (int i = 0; i < n; i++)
		{
			maxEnd = maxEnd + A[i] > A[i] ? maxEnd + A[i] : A[i];
			maxNow = maxNow > maxEnd ? maxNow : maxEnd;
		}
		return maxNow;
		
		//divide and conquer method, but it runs out of time.ELT
		//if (n < 1) return 0;
		int res = getMaxSubArray(A, 0, n - 1);
		return res;
	}

	int getMaxSubArray(int A[], int begin, int end)
	{
		if (begin == end) return A[begin];
		int middle = (begin + end) / 2;

		int left = getMaxSubArray(A, begin, middle);
		int right = getMaxSubArray(A, middle + 1, end);

		//int midSum = A[middle] + A[middle+1];
		int midLeft =0, midRight =0;
		int midLeftMax = A[middle], midRightMax= A[middle+1];
		for (int i = middle; i >= 0; i--)
		{
			midLeft += A[i];
			if (midLeft > midLeftMax) midLeftMax = midLeft;
		}
		for (int j = middle + 1; j <= end; j++)
		{
			midRight += A[j];
			if (midRight > midRightMax) midRightMax = midRight;
		}
		int midSum = midLeftMax + midRightMax;

		int res = left > right ? left : right;
		res = res > midSum ? res : midSum;
		return res;
	}
};