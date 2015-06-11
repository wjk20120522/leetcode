class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E);
        int right = min(C,G);

        int up = min(H,D);
        int down = max(B,F);

        int overlap = (right-left) * (up-down);

        int area = (D-B) *(C-A) + (H-F) * (G-E);

        if(right -left < 0 || up - down < 0) return area;   // no overlap
        return area - overlap;
    }
};