//C++ 
#include <bits/stdc++.h> 
#include <iostream>
#define MOD 1000000007
using namespace std;

int n;
struct Point {
    long long x;
    long long y;
    long long c;
};

vector<Point> points;

long long cur_max[1001];

void sort_by_sec() {
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x != points[start].x) {
            sort(points.begin() + start, points.begin() + i, [] (Point p1, Point p2) {
               return p1.y < p2.y;
            });
            start = i;
        }
    }
    
    sort(points.begin() + start, points.end(), [] (Point p1, Point p2) {
       return p1.y < p2.y;
    });    
    
    // for (int i = 0; i < n; i++) {
    //     cout << points[i][0] << " " << points[i][1] << "\n";
    // }
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    long long x, y, c;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> c;
        Point p{x, y, c};
        
        points.push_back(p);
    }
    
    sort(points.begin(), points.end(), [] (Point p1, Point p2) {
       return p1.x < p2.x;
    });
    sort_by_sec();
    
    long long res = points[0].c;
    cur_max[0] = res;
    
    for (int i = 1; i < n; i++) {
        long long y1 = points[i].y, c1 = points[i].c;
        cur_max[i] = c1;
        
        for (int j = i - 1; j >= 0; j--) {

            if (y1 >= points[j].y) {
                cur_max[i] = max(cur_max[i], cur_max[j] + c1);
            }
        }
        res = max(res, cur_max[i]);
    }
    
    cout << res;
}

