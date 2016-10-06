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
    int GCD(int x, int y) {
        if (y == 0) return x;

        return GCD(y, x%y);
    }

    int maxPoints(vector<Point>& points) {
        map<pair<int, int>, int> m;
        int result = 0, localmax, vertical, overlap;
        size_t size = points.size();

        for (size_t i=0; i<size; i++) {
            m.clear();
            localmax = 1;
            vertical = overlap = 0;

            for (size_t j=i+1; j<size; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    // overlap
                    overlap++;
                    localmax += 1;
                } else if (points[j].x == points[i].x) {
                    // vertical
                    vertical++;
                } else {
                    int dx = points[i].x - points[j].x;
                    int dy = points[i].y - points[j].y;
                    int gcd = GCD(dx, dy);

                    dx /= gcd;
                    dy /= gcd;

                    m[make_pair(dx, dy)]++;

                    localmax = max(localmax, m[make_pair(dx, dy)] + overlap + 1);
                }
            }

            localmax = max(localmax, vertical + overlap + 1);
            result = max(result, localmax);
        }

        return result;
    }
};
