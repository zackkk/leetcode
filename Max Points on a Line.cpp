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
        if(points.size() == 0) return 0;
        int maxnum = 0;
        map<float, int> m; // <slope, count>
        for(int i = 0; i < points.size(); i++){ // for each point, find a line with max points
            int itself = 0;  // corner case 1
            int infinite = 0; // corner case 2, vertical to x-axis
            for(int j = 0; j < points.size(); j++){
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;
             
                if(x == 0 && y == 0) { itself++; }
                else if(x == 0) { infinite++; }
                else{
                    float k = (float)y / x;
                    if(!m[k]) m[k] = 1;
                    else m[k]++;
                }
            }
            int tmp = 0;
            for(auto it = m.begin(); it != m.end(); ++it){   // used for loop, bug happened here
                tmp = max(tmp, it->second);
            }
            maxnum = max(maxnum, tmp + itself);
            maxnum = max(maxnum, infinite + itself);
            m.clear();
        }
        return maxnum;
    }
};
