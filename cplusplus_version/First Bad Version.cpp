// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1, end = n, mid;
        while (true) {
            mid = begin + (end - begin) / 2;
            if (isBadVersion(mid)) {
                if (mid == 1 || !isBadVersion(mid - 1)) {
                    return mid;
                } else {
                    end = mid - 1;
                }
            } else {
                begin = mid + 1;
            }
            if(begin > end) {
                break;
            }
        }
        return -1;
    }
};