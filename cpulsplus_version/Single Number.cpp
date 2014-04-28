#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        n--;
		for(; n>=1; n--) {
        	A[n-1] = A[n]^A[n-1];  
        }
        return A[0];
    }
};

int main() {
	Solution s;
	int Arr[] = {1,1,2,3,2,3,4,5,5};
	cout<<s.singleNumber(Arr,9)<<endl;
	return 0;
}