#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> temp_vec(numbers);
		sort(numbers.begin(), numbers.end());
		vector<int>::iterator it_begin = numbers.begin(), it_end = numbers.end();
		int begin = 0, end = numbers.size()-1;
		for(; begin < end; ) {
			int temp = numbers[begin] + numbers[end];
			int one,two;
			if(temp == target) {
				for(int i=0; i<temp_vec.size(); i++) {
					if(numbers[begin] == temp_vec[i] || numbers[end] == temp_vec[i]) {
						one = i+1;
						break;
					}
				}
				for(int i=0; i<temp_vec.size(); i++) {
					if((numbers[end] == temp_vec[i] ||numbers[begin] == temp_vec[i] ) && i >= one ) {
						two = i+1;
						break;
					}
				}
			
				vector<int> res(2);
				res[0] = one ; res[1] = two;
				return res;
			}
			if(temp < target) {
				begin ++;
			} else {
				end --;
			}
		}
    }
};

int main() {
	Solution s;
	const int num = 3;
	vector<int> v(num);
	
	v[0] = 5; v[1] = 75; v[2] = 25; 
	
	vector <int> res;
	
	res = s.twoSum(v,100);
	cout<<res[0]<<" "<<res[1]<<endl;
}