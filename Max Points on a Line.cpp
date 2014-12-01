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
    // y = kx + b
    int maxPoints(vector<Point> &points) {
        int max_num = 0;
        
        for(Point p : points){
            
            int itself = 0;
            int vertical = 0;
            map<double, int> m;
            for(Point q : points){
                if(q.x == p.x && q.y == p.y) { itself++; continue; }
                if(q.x == p.x) { vertical++; continue; }
                
                double k = (double)(q.y - p.y) / (q.x - p.x);
                m[k]++;
            }
            
            max_num = max(max_num, itself + vertical);
            int max_tmp = 0;
            for(auto it = m.begin(); it != m.end(); ++it)
                max_tmp = max(max_tmp, it->second);
            max_num = max(max_num, itself + max_tmp);
        }
        
        return max_num;
    }
};
