class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int totalArea;
        int overlapArea = 0;
        totalArea = (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1);
        int nx = min(ax2,bx2)-max(ax1,bx1);
        int ny = min(ay2,by2)-max(ay1,by1);
        if(nx>0 and ny>0)
            totalArea -= nx*ny;
        return totalArea;
    }
};