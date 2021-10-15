#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>

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

    d = sqrt(pow((maxpoint.x - currentpoint.x), 2) + pow((maxpoint.y - currentpoint.y), 2));

    return d;
}
float distance(point currentpoint, point nextpoint){
    float d;
    d = sqrt(pow((nextpoint.x - currentpoint.x), 2) + pow((nextpoint.y - currentpoint.y), 2));
    return d;
}

void solve(){

    float totalSurfaceArea = 0;

    sort(points.begin(), points.end(), cmp);
    // debug
    // printPoints();

    for (int i = 0; i < points.size() - 2; i++){
        // getting the max point that is less than the current (in terms of y)
        point maxpoint(-1, -1);
        for (int j = i + 1; j < points.size(); j++){
            if (points[i].y <= points[j].y){
                maxpoint.setpoints(-1,-1);
                break;
            }
            if (points[j].y < points[i].y && points[j].y > maxpoint.y){
                maxpoint.setpoints(points[j].x, points[j].y);
            }
        }
        // if x, y of maxpoint are -1 then the point is hidden
        if (maxpoint.x != -1){
            totalSurfaceArea += calculateSurfaceArea(maxpoint,points[i],points[i+1]);
        }
        // cout << "current point: [" << points[i].x << "," << points[i].y << "]" << endl
        //         << "maxpoint: [" << maxpoint.x << "," << maxpoint.y << "]" << endl;
    }
    // add last calculation for second to last and last point
    totalSurfaceArea += distance(points[points.size() - 2],points[points.size() - 1]);
    cout << setprecision(2) << fixed << totalSurfaceArea << endl;
}

int main(){

    ifstream cin("input4.txt");

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
        
        // cout << "case: " << c << endl;
        solve();
        
        points.clear();
    }

}