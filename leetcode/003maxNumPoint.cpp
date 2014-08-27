#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <sstream>

using namespace std;

#define debug(x, y) std::cout << "debug: " << x << ": "<< y << endl;

struct Point {
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    
    void toString() { std::cout << "{" << x << "," << y << "}" << std::endl;  };

    int x;
    int y;
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        
        string keyX = "x";
        string keyY = "y";
        string keyXplusY = "x+y";
        string keyXminuxY = "x-y";
        int x;
        int y;

        map<string, int>::iterator index;

        map<string, int> numMap;
        for( vector<Point>::iterator it = points.begin(); it != points.end(); it++ )
        {
            x = (*it).x;
            y = (*it).y;

            string key4X = keyX + int2str(x);
            string key4Y = keyY + int2str(y);
            string key4XplusY = keyXplusY + int2str(x + y);
            string key4XminusY = keyXminuxY + int2str(x - y);
            if( (index = numMap.find(key4X)) == numMap.end() )
                numMap[key4X] = 1;
            else
                numMap[key4X]++;
            
            if( (index = numMap.find(key4Y)) == numMap.end() )
                numMap[key4Y] = 1;
            else
                numMap[key4Y]++;

            if( (index = numMap.find(key4XplusY)) == numMap.end() )
                numMap[key4XplusY] = 1;
            else
                numMap[key4XplusY]++;
            
            if( (index = numMap.find(key4XminusY))== numMap.end() )
                numMap[key4XminusY] = 1;
            else
                numMap[key4XminusY]++;
            
        }
        int maxNumPoint = 0;
        for( map<string, int>::iterator it = numMap.begin(); it != numMap.end(); it++ )
        {
            maxNumPoint = maxNumPoint > it->second ? maxNumPoint : it->second;
        }
        return maxNumPoint;
    }

    string int2str(int i){
        string s;
        stringstream ss(s);
        ss << i;
        return ss.str();
    }   

};



int main()
{
    Point ps1[16] = {Point(0,0), Point(0,1), Point(0,2), Point(0,3),
                   Point(1,0), Point(1,1), Point(1,2), Point(1,3),
                   Point(2,0), Point(2,1), Point(2,2), Point(2,3),
                   Point(3,0), Point(3,1), Point(3,2), Point(3,3)};
    
    Solution* solver = new Solution();
    
    vector<Point> points1(ps1,ps1+15);
    int max1 = solver->maxPoints(points1);
    
    vector<Point> points2;
    int max2 = solver->maxPoints(points2);
    
    Point ps3[1] = {Point(1,1)};
    vector<Point> points3(ps3, ps3+1);
    int max3 = solver->maxPoints(points3);

    debug("ps1-maxNumOfPoints", max1);
    debug("ps2-maxNumOfPoints", max2);
    debug("ps3-maxNumOfPoints", max3);
    return 0;

}
