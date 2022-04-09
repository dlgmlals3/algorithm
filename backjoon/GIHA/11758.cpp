// CCW 알고리즘
#include <iostream>
using namespace std;

struct Point { 
    int x, y;
};

int main(void) {
    Point p[3];
    for (int i=0; i<3; i++) {
        cin >> p[i].x >> p[i].y;
    }
    int a = (p[0].x*p[1].y) + (p[1].x*p[2].y) + (p[2].x * p[0].y);
    int b = (p[1].x*p[0].y) + (p[2].x*p[1].y) + (p[0].x * p[2].y);
    if (a - b >= 0) {
        if (a == b) {
            cout << "0" << endl;
        } else {
            cout << "1" << endl;
        }        
    } else {
        cout << "-1" << endl;
    }
    return 0;
}