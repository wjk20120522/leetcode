/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float,int> unmap;
        int i;
        int maxNum = 0;
        for(i=0; i<points.size(); i++) {
            unmap.clear();
            unmap[INT_MIN] = 0;
            //calculate the i point maxNum
            int j,duplicate = 1; //at least one point as i itself
            for(j=0; j<points.size(); j++) {
                if(j==i) continue;
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate ++;
                    continue;
                }
                float slope = (points[i].x == points[j].x) ? INT_MAX : (float)(points[i].y-points[j].y)/(points[i].x-points[j].x);
                unmap[slope] ++;
            }
            unordered_map<float,int>::iterator it;
            for(it=unmap.begin(); it!=unmap.end(); it++) {
                if(it->second+duplicate > maxNum) {
                    maxNum = it->second+duplicate;
                }
            }
        }
        return maxNum;
    }
};