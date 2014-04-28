#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        int bits[32] = {0};

     	for(int j=0; j<32;j++) {
     		for(int i=0; i<n; i++) {
     			bits[j] += (A[i] >> j) & 1;
     		}
     		res |= ((bits[j] % 3) << j);
        }
        return res;
    }
};

int main() {
	Solution s;
	
	int Arr[] = {1,1,1,2,2,2,3,5,5,5};
	cout<<s.singleNumber(Arr,10)<<endl;
	return 0;
}