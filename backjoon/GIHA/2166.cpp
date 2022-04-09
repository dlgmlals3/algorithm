// CCW 결과값 / 2는 삼각형의 넓이,, 사각형은 삼각형 2개로 만들어서 품.
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

using Point = pair<long, long>;

long long clockWise(Point p1, Point p2, Point p3) {
    long long a = (p1.first*p2.second) + (p2.first*p3.second) + (p3.first*p1.second);
    long long b = (p2.first*p1.second) + (p3.first*p2.second) + (p1.first*p3.second);
    return a - b;
}

int main(void) {
    int N;
    cin >> N;
    vector<Point> v;
    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    long long sum = 0;
    for (int i=0; i<N-2; i++) {
        long long area = clockWise(v[i], v[i+1], v[i+2]);
        if (area < 0) area *= -1;
        sum += area;
    }
    cout << sum / 2 << '.';
    if (sum % 2 == 0) {
        cout << '0';
    } else {
        cout << '5';
    }
    cout << '\n';
    return 0;
}