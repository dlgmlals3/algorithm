// 선분교차인데 한점이 한선분의 끝점에 있어도 교차하는것

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

using Point = pair<long, long>;
using Line = pair<Point, Point>;

int clockWise(Point p1, Point p2, Point p3) {
    long long a = (p1.first*p2.second) + (p2.first*p3.second) + (p3.first*p1.second);
    long long b = (p2.first*p1.second) + (p3.first*p2.second) + (p1.first*p3.second);
    long long tmp = a - b;
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}

bool cross(Line l1, Line l2) {
    int l1l2 = clockWise(l1.first, l1.second, l2.first) * clockWise(l1.first, l1.second, l2.second);
    int l2l1 = clockWise(l2.first, l2.second, l1.first) * clockWise(l2.first, l2.second, l1.second);
    // 두 선이 일직선인 경우
    if (l1l2 == 0 && l2l1 == 0) {
        if (l1.first > l1.second) swap(l1.first, l1.second);
        if (l2.first > l2.second) swap(l2.first, l2.second);
        return l2.first <= l1.second && l1.first <= l2.second; 
    }

    // A - B 선분이 있고 C 점이 A - B 선분에 접할때
    return l1l2 <= 0 && l2l1 <= 0; 
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Point p1, p2, p3, p4;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;
    Line l1 = {p1, p2};
    Line l2 = {p3, p4};
    
    cout << cross(l1, l2) ? 1 : 0 << '\n';

    return 0;
}