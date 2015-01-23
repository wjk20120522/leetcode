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
        int result = 0;

         for (int i = 0; i < points.size(); i++) {
             int samepoint = 1;

             unordered_map<double, int> map;
             for (int j = i + 1; j < points.size(); j++) {
                 //the same point
                 if (points[i].x == points[j].x && points[i].y == points[j].y) {
                     samepoint++;
                 }
                 // x axis
                 else if (points[i].x == points[j].x) {
                     map[INT_MAX]++;
                 }
                 else {
                     double slope = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                     map[slope]++;
                 }   
             }
             int localMax = 0;
             for (auto it = map.begin(); it != map.end(); it++) {
                 localMax = max(localMax, it->second);
             }
             result = max(result, localMax + samepoint);
            
         }
         return result;
    }
};