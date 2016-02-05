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
    int maxPoints(vector<Point>& points) {
        if(points.size() <= 1) return points.size();
        vector<int> res;
        int myMax = INT_MIN;
        for(int i = 0; i < points.size() ; i ++){
            int verCount = INT_MIN;
            unordered_map<double, int> k;
            int base = 1;
            for(int j = 0; j < points.size() ; j ++){
                
                if(i == j) continue;
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                     base ++;
                }else if(points[i].x == points[j].x){
                    if(verCount == INT_MIN)verCount = 0;
                    verCount ++;
                }else{
                    double tmpK = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x);
                    if(k.find(tmpK) == k.end()){
                        k[tmpK] = 1;
                    }else{
                        k[tmpK] ++;
                    }
                    if(k[tmpK] + base > myMax) myMax = k[tmpK] + base;
                }
            }
            
            if(verCount + base > myMax) myMax = verCount + base;
            if(base > myMax) myMax = base;
        }
        
        return myMax == INT_MIN ? 2 : myMax;
    }
};
