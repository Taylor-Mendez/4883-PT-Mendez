#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point;

int c,n;
vector<point> points;
int x,y;

struct point{
    int x,
        y;

    point():x{0}, y{0}{}
    point (int x, int y):x{x},y{y}{}
};

bool cmp(point &a, point &b){
    return a.x < b.x;
}

void printPoints(){
    for (int i = 0; i < points.size(); i++){
        cout << "[" << points[i].x << "," << points[i].y << "] ";
    }
}

int main(){

    cin >> c;
    while(c--){
        cin >> c;
        while(n--){
            cin >> x >> y;
            points.push_back(point(x,y));
        }
    }

    sort(points.begin(), points.end(), cmp);
    printPoints(); // debug
    points.clear();


}