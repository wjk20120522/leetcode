#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
    	int res = 0;
    	int temp = x;
    	if(x < 0) {
    		return false;
    	}
    	while(x) {
    		res = res*10 + x%10;
    		x /= 10;
    	}
    	if(temp == res) {
    		return true;
    	}
    	return false;
    }
};

int main() {
	int x = 1;
	
	Solution s;
	std::cout<<"res"<<s.isPalindrome(x)<<std::endl;
}