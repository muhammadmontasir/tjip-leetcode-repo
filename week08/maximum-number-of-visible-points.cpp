// TC: O(N^2)
// MC: O(N)
class Solution {
public:
    double getAngle(double dy, double dx) {
        double rad = atan2(dy, dx);
        double deg = 180.0 * rad / acos(-1.0);
        
        return deg < 0 ? deg + 360 : deg;
    }
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int duplicates = 0;
        for (auto &point : points){
            if (point == location) duplicates++;
            else angles.push_back(getAngle(point[1] - location[1], point[0] - location[0]));
        }
        
        sort(angles.begin(), angles.end());
        
        int max_point = 0;
        int n = angles.size();
        for (int lower_ray = 0, upper_ray = 0; lower_ray < n; lower_ray++){
            while((upper_ray < n && angles[upper_ray] - angles[lower_ray] <= angle) || (upper_ray >= n && 360 + angles[upper_ray % n] - angles[lower_ray] <= angle)) {
                upper_ray++;
            }
            max_point = max(max_point, upper_ray - lower_ray);
        }
        return max_point + duplicates;
    }
};