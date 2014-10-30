#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int target_one = -1,target_two = -1;
        int middle;
        int begin = 0, end = n-1;
        while(begin <= end) {
            middle = (begin+end)/2;
            if(A[middle] < target) {
                begin = middle + 1;
            } else if(A[middle] > target ) {
                end = middle - 1;
            } else {
                break;
            }
        }
        if(begin <= end ) {
            //target_one = begin;
            int temp_begin = begin, temp_end = middle;
            target_one = (temp_begin + temp_end) / 2;
            while(temp_begin < temp_end) {
                if(A[target_one] == target) {
                    if( target_one >0 && A[target_one-1] == target ) {
                        temp_end = target_one - 1;
                    } else {
                        temp_begin = target_one ;
						temp_end = target_one;
                    }
                    
                } else {
                    temp_begin = target_one + 1;
                }
                target_one = (temp_begin + temp_end) / 2;
            }

            temp_begin = middle, temp_end = end;
            target_two = (temp_begin + temp_end) / 2;
            while(temp_begin < temp_end) {
                if(A[target_two] == target) {
                        if(target_two <end &&  A[target_two +1] == target) {
                            temp_begin = target_two + 1;
                        } else {
                            temp_end = target_two;
							temp_begin = target_two;
                        }    
                } else {
                    temp_end = target_two - 1;
                }
                target_two = (temp_begin + temp_end) / 2;
            }
        }
        vector<int> res(2);
        res[0] = target_one, res[1] = target_two;
        return res;

        //another method
        /*

        //  int begin = -1, end = -1;
        vector<int> res;
        int left = 0, right = n - 1;
        int middle;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (A[middle] == target)
                break;
            else if (A[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        if (A[middle] == target)
        {
            int tmp = middle;

            int leftmost = middle, rightmost = middle;
            while (left < tmp)
            {
                leftmost = left + (tmp - left) / 2;
                if (A[leftmost] == target)
                {
                    tmp = leftmost;
                }
                else
                {
                    left = leftmost+1;
                }
            }
            res.push_back(tmp);

            tmp = middle;
            while (tmp < right)
            {
                rightmost = tmp + (right - tmp) / 2;
                if (A[rightmost] == target)
                {
                    if (A[rightmost+1] == target)
                        tmp = rightmost+1;
                    else
                    {
                        res.push_back(rightmost);
                        return res;
                    }
                        
                }
                else
                {
                    right = rightmost-1;
                }
            }
            res.push_back(tmp);
            return res;

        }
        else
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }

        */

    }
};

int main() {
	Solution s;
	
	int Arr[] = {1,1,2};
	cout<<s.searchRange(Arr,3,1)[0]<<" "<<s.searchRange(Arr,3,1)[1]<<endl;
	return 0;
}