#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
#include <math.h>

using namespace std;

struct point;

int c,  // number of test cases
    n;  // number of points in a particular test case

vector<point> points;
float x,y;    // to read in points

struct point{
    float x,
        y;

    point():x{0}, y{0}{}                // i think constructor
    point (float x, float y):x{x},y{y}{}    // set x and y

    void setpoints(float newx, float newy){
        x = newx;
        y = newy;
    };
};

// to sort points by x
bool cmp(point &a, point &b){
    return a.x < b.x;
}

void printPoints(){
    for (int i = 0; i < points.size(); i++){
        cout << "[" << points[i].x << "," << points[i].y << "] " << endl;
    }
}


// y = mx+b
// slope = m
// intercept = b
float calculateSurfaceArea(point maxpoint, point currentpoint, point nextpoint){
    float slope, intercept;
    float d;        // surface area between currentpoint and where maxpoint intersects

    // get new point where it intersects on the slope
    slope = (nextpoint.y - currentpoint.y) / (nextpoint.x - currentpoint.x);
    intercept = currentpoint.y - slope * currentpoint.x;

    maxpoint.x = (maxpoint.y - intercept) / slope;

    // calculate surface area using distance formula
    // d = sqrt((x2-x1)^2 + (y2-y1)^2)

    d = sqrt(pow((maxpoint.x - currentpoint.x), 2) + pow((maxpoint.x - currentpoint.x), 2));

    return d;
}

void solve(){

    float totalSurfaceArea = 0;

    sort(points.begin(), points.end(), cmp);
    printPoints(); // debug

    for (int i = 0; i < points.size(); i++){
        // point maxpoint(0, 0);

        point maxpoint(points[i].x, points[i].y);   //test
        int index = 0;
        // getting the max point that is less than the current (in terms of y)
        for (int j = i + 1; j < points.size(); j++){
            if (j == points.size() - 1){
                // calculate the whole slope and add
                break;
            }
            if (points[i].y < points[j].y){
                maxpoint.setpoints(0,0);
                break;
            }
            if (points[j].y < points[i].y && points[j].y >= maxpoint.y){
                maxpoint.setpoints(points[j].x, points[j].y);
            }
        }

        // do some calculations with max point and current
        cout << "current point: [" << points[i].x << "," << points[i].y << "]" << endl
             << "maxpoint: [" << maxpoint.x << "," << maxpoint.y << "]" << endl;

    }
}

int main(){

    ifstream cin("input.txt");

    cin >> c;

    // while we still have test cases
    while(c--){
        int total = 0;      // not really sure what this is or why i added it but leaving for now
        cin >> n;
        // read in all points
        while(n--){
            cin >> x >> y;
            points.push_back(point(x,y));
        }
        
        cout << "case: " << c << endl;
        solve();
        
        points.clear();
    }

}